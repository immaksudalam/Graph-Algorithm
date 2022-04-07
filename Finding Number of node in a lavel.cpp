#include <bits/stdc++.h>
using namespace std;
int level[1000];
int parent[1000];
int vis[1000];
vector<int>v[1000];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    parent[src]=-1;
    level[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it=v[u].begin(); it!=v[u].end(); it++){
            int vv = *it;
            if(!vis[vv]){
                vis[vv]=1;
                q.push(vv);
                level[vv]= level[u]+1;
                parent[vv]=u;
            }
        }
    }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x;
    cin>>x;
    int cnt=0;
    bfs(1);
    for(int i=1; i<=n; i++){
        if(level[i]==x-1){
             cnt++;
        }
    }
    cout<<cnt<<endl;
}
