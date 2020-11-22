/* Tarjent algorithm:
    there are two criteria for a node to become a articulation point.
      1. if its root node, it must have more than one child.
      2. if its a child node,
          visit time at this node <= low time of any of its adjacency node.
    Low time updation rule:
      1. when child return to its parent node.
           low[parent] = min(low[parent], low[child]);
      2. if its back edge
         low[parent] = min(low[parent], visit_time[child]);
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 3001
vector<int>graph[mx]; //adjacency list
int visited[mx], visit_time[mx], low[mx], parent[mx];
vector<int>articulationPoint;
int timer=0;
int dfs(int src)
{
    visited[src]=1;
    visit_time[src]=low[src] = ++timer;
    for(int i=0; i<graph[src].size(); i++){
        int v = graph[src][i];
        if(!visited[v]){
            parent[v] = src;
            dfs(v);
            //before return to parent node.
            if(parent[src]==-1){
                if(i>=1){ //fist case of articulation piont.
                    articulationPoint.push_back(src+1); // src is the root node & it has more than one child.
                }
            }
            else if(low[v] >= visit_time[src]){ // 2nd case of articulation point.
                articulationPoint.push_back(src+1);
                low[src] = min(low[src], low[v]);
            }
        }
        else if(v != parent[src]){ //Back edge
            low[src] = min(low[src], visit_time[v]);
        }
    }
}

int main()
{
    int node, edge;
    cin>>node>>edge;
    for(int i=0; i<edge; i++){
        int u,v;
        cin>>u>>v;
        u--, v--; // for 0 indexing.
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    memset(visit_time, -1, sizeof(visit_time));
    memset(low, -1, sizeof(low));
    dfs(0);
    cout<<"Printing articulation points"<<endl;
    for(int i=0; i<articulationPoint.size(); i++){
        cout<<articulationPoint[i]<<" ";
    }cout<<endl;
}

/*9 10
1 2
1 3
2 3
3 4
4 5
5 7
5 8
7 8
8 9
9 6*/
