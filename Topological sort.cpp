/*
    --> topological sort possible in Directed acyclic graph.
    there are two ways to find topological sort.
       1) using starting time & finishing time to visit a node, take node regarding to its finishing node
          which finishing time is larger take first.
       2) using stack. when a node complete to visit all of his adjacency nodes, then put this
          in stack. finally the topological sorted order is to output the stack in regular manner.

*/
#include <bits/stdc++.h>
using namespace std;
#define mx 301
vector<int> graph[mx];
int visited[mx], starting_time[mx], finishing_time[mx];
int timer=0;
stack<int>st;
void dfs(int src)
{
    visited[src]=1;
    starting_time[src]=++timer;
    for(int i=0; i<graph[src].size(); i++){
        int v = graph[src][i];
        if(!visited[v]) dfs(v);
    }
    finishing_time[src] = ++timer;
    st.push(src+1); // 0 indexing
}
int main()
{
    int node, edge;
    cin>>node>>edge;
    for(int i=0; i<edge; i++){
         int u, v; cin>>u>>v;
         u--, v--; // 0 indexing
         graph[u].push_back(v);
    }
    for(int i=0; i<node; i++){
        if(!visited[i]) dfs(i);
    }
    cout<<"The order after topological sort "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}
