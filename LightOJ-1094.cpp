#include <bits/stdc++.h>
using namespace std;
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define f first
#define s second

bool visited[30001];
vector<pair<int,int> > v[30001];
int n[30001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int len = v[u].size();
        for (int i = 0; i < len; i++)
        {
            if(!visited[v[u][i].f])
            {
                n[v[u][i].f] = n[u] + v[u][i].s;
                visited[v[u][i].f] = 1;
                q.push(v[u][i].f);
            }
        }
    }
}

int main()
{
     int nd;
     scanf("%d", &nd);
     int j = 1;
     while(nd--)
     {
         int a;
         scanf("%d", &a);
         for (int i = 1; i < a; i++)
         {
             int x,y,z;
             scanf("%d %d %d" , &x , &y , &z);
             v[x].push_back(make_pair(y,z));
             v[y].push_back(make_pair(x,z));
         }
         bfs(0);
         int ind = 0,mx =0;
         for (int k = 0; k < a; k++)
         {
            if(n[k] > mx)
            {
                mx = n[k];
                ind = k;
            }
         }
         mem(n,0);
         mem(visited,0);
         bfs(ind);
         for (int k = 0; k < a; k++)
         {
            if(n[k] > mx)
                mx = n[k];
         }
        printf("Case %d: %d\n",j++,mx);
         for (int k = 0; k <= a; k++) {
             v[k].clear();
         }
         mem(visited,0);
         mem(n,0);
     }
}
