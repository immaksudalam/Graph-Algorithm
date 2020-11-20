#include <bits/stdc++.h>
using namespace std;
#define mx 100
typedef pair<int, int> pii; // weighted adjacency list.
//first element neighboring node
//second element weight of the edge
vector <pii> v[mx];
struct node{
    int u, cost;
};
bool operator <(node a, node b){
    return a.cost > b.cost;
}
priority_queue<node> pq;
int cost[mx];
bool visited[mx];
int vertex, edge;

int prim(int sourch)
{
    for(int i=0; i<vertex; i++){
        cost[i]=INT_MAX;
        visited[i]=false;
    }

    cost[sourch] = 0;
    node temp;
    temp.u = sourch;
    temp.cost =0;
    pq.push(temp);
    int ans =0;

    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        if(visited[current.u]) continue;
        visited[current.u] = true;
        ans+= current.cost;

        for(int i=0; i< v[current.u].size(); i++){
            node temp1;
            temp1.u = v[current.u][i].first;
            temp1.cost = v[current.u][i].second;
            pq.push(temp1);
            cost[v[current.u][i].first] = v[current.u][i].second;
        }
    }
    return ans;
}
void printGraph(){
    for(int i=0; i<vertex; i++){
        cout <<i<<" -- ";
        for(int j=0; j< v[i].size(); j++){
            cout<< v[i][j].first <<" "<<v[i][j].second<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>vertex>>edge;
    for(int i=0; i<edge; i++){
        int sourch;
        pii p;
        cin>>sourch;
        cin>>p.first>>p.second;
        sourch--;
        p.first--;
        v[sourch].push_back(p);
        int sourch1 = p.first;
        p.first = sourch;
        v[sourch1].push_back(p);
    }
    printGraph();
    cout<<prim(0)<<endl;
}
