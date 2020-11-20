#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5+5;
struct edge{
   int u, v, w;
};
vector<edge> graph, output;
int parent[maxn], mstval=0;

bool cmp(edge a, edge b){
    return a.w < b.w;
}
void make_set(int n)
{
    parent[n] = n;
    //Rank[n] =1;
}
int find(int x)
{
    if(parent[x]!=x) parent[x] = find(parent[x]);
    return parent[x];
}
void kruskal_Algorithm(int n)
{
    sort(graph.begin(), graph.end(), cmp); // const er bittite increasing order e sort kora holo
    for(int i=0; i<n; i++) make_set(i); // for union find. make set.
    int cnt =0;
    for(int i=0; i<(int)graph.size(); i++){
        int upr = find(graph[i].u);
        int vpr = find(graph[i].v);
        // দুইটা নোডের প্যারেন্ট সমান মানে এদের যুক্ত করা হলে সাইকেL হয়ে যাব
        if(upr != vpr){
            if(cnt == n-1) break;
            output.push_back(graph[i]);
            mstval += graph[i].w;
            parent[upr] = vpr; // এটা নেওয়া হয়ে গেছে তার মানে এর পেরেন্ট আপডেট করতে হবে । এবং তাই করেছি
            cnt++;
        }
    }
}
int main()
{
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++) {
        edge input;
        cin>>input.u>>input.v>>input.w;
        graph.push_back(input);
    }
    kruskal_Algorithm(n);
    cout<<mstval<<endl;
    for(int i=0; i< output.size(); i++){
        //cout<<output[i].u<<" "<<output[i].v<<" "<<output[i].w<<endl;
    }
}
