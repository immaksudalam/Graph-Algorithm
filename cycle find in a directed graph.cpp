#include <bits/stdc++.h>
using namespace std;
#define mx 1000
vector<int>graph[1000];
bool visited[mx];
int white[mx], grey[mx], black[mx];
int path[mx];
bool cycle=false;
int pathsrc;
int pathend;
int dfs(int src)
{
    visited[src]=1;
    grey[src]=1;
    for(int i=0; i<graph[src].size(); i++){
        int v = graph[src][i];
        if(grey[v]){
           cycle=true;
           pathsrc = src;
           pathend = v;
        }
        if(!visited[v]){
              path[v]=src;
              dfs(v);
            }
    }
    grey[src]=0;
}
int main()
{
    int node, egde;
    cin>>node>>egde;
    for(int i=0; i<egde; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    dfs(4);
    if(!cycle)cout<<"No cycle found"<<endl;
    else{
        cout<<"cycle ditected"<<endl;
        vector<int>p;
        p.push_back(pathend);
        while(pathend!=pathsrc)
            {
              p.push_back(pathsrc);
              pathsrc= path[pathsrc];
          }
          p.push_back(pathsrc);
        reverse(p.begin(), p.end());
        for(int i=0; i<p.size(); i++){
            cout<<p[i]<<" ";
        }cout<<endl;
    }
}
