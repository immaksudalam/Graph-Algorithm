#include <bits/stdc++.h>
using namespace std;
vector<int> G[100];
int visited[100] = {0};
int level[100];
int parent[100];
void bfs(int src, int n)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;
    level[src]=0;
    while(!q.empty()){
        int u = q.front();
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            if(!visited[v]){
                level[v]= level[u]+1;
                parent[v]=u;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }

    for(int i=1; i<=n; i++){
        printf("%d to %d distance %d\n", src, i, level[i]);
    }
}
int main()
{
   int node, egde;
   cin>>node>>egde;
   for (int i=0; i<egde; i++) {
      int x,y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
   }
      bfs(1, node);
}
