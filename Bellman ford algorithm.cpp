#include <bits/stdc++.h>
using namespace std;
#define mx 10000
#define INF 10000
int main()
{
    int node, egde;
    int ua[mx], va[mx], weight[mx];
    cin>>node>>egde;
    int distance[node+1];
    memset(distance, INF, sizeof(distance));
    bool neg_cycle = false;
    int path[mx];
    for(int i=1; i<=egde; i++){
        cin>>ua[i]>>va[i]>>weight[i];
    }
    distance[1]=0;
    for(int step=1; step<=node; step++){
       bool update = false;
       for(int i=1; i<=egde; i++){
         int u = ua[i];
         int v = va[i];
         if(distance[v]> distance[u] + weight[i]){
            distance[v]= distance[u]+weight[i];
            update=true;
            path[v]=u;
            if(step==node)neg_cycle=true;
         }
       }
        if(update==false)break;
    }
    if(neg_cycle){
        cout<<"Negetive cycle detected!!!"<<endl;
    }
    else{
        for(int i=1; i<=node; i++){
            cout<<"Distance of Node: " << i << " is: " << distance[i] << endl;
        }
    }

    int p;
    cin>>p;
    vector<int> v;
    int src=1;
    while(p!=src){
        v.push_back(p);
        p = path[p];
    }
    v.push_back(p);
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}
