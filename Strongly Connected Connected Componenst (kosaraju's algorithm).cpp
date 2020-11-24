/*
   time complexity O(v+E)
   space complesity O(V) // both of stack & visited array

   Find strongly connected components using kosaraju's algorithm:
     1) traverse the graph using dfs
     2) store element in stack regarding to their finishing time ( as like as topological sort)
     3) store graph in reverse order. (given order -> reverse order)
     4) take the top element from the stack. if this element is not visited, we must find here a
        new strongly connected component group. so for find this group, we just call another dfs.
        if top element is already visited. just continue;
     5) pop top most element from stack.
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 301
vector <int>graph[mx], rGraph[mx];
vector<int>v;
vector<vector<int> >vec;
int visited[mx];
stack<int> st;
void dfs(int src)
{
    visited[src]=1;
    for(int i=0; i<graph[src].size(); i++){
        int v = graph[src][i];
        if(!visited[v]) dfs(v);
    }
    st.push(src);
}
void rdfs(int src)
{
    visited[src]=1;
    v.push_back(src);
    for(int i=0; i<rGraph[src].size(); i++){
        int v = rGraph[src][i];
        if(!visited[v]) rdfs(v);
    }
}
int main()
{
    int node, edge; cin>>node >> edge;
    for(int i=0; i<edge; i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        rGraph[y].push_back(x);
    }
    for(int i=1; i<=node; i++){
          if(!visited[i]) dfs(i);
    }
    memset(visited, 0, sizeof(visited));
    int pos=0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            rdfs(u);
        }
        vec.push_back(v);
        v.clear();
    }
    for(int i=0; i<vec.size(); i++){
        bool f=false;
        sort(vec[i].begin(), vec[i].end());
        for(int j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" ";
            f=true;
       }
        if(f)cout<<endl;
    }
}
/*
11 13
1 3
3 2
2 1
1 4
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7
10 11
*/
