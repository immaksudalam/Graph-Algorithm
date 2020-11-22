#include <bits/stdc++.h>
using namespace std;
#define mx 100
#define INF INT_MAX
int graph[mx][mx];
int w[mx][mx];
void floyedwarshall(int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) w[i][j]=graph[i][j];

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
         for(int j=0; j<n; j++){
             if(w[i][j] > w[i][k]+w[k][j])
                w[i][j]=w[i][k]+w[k][j];
         }
}
void printw(int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(w[i][j]==INF)cout<<"INF"<<" ";
            else cout<<w[i][j]<<" ";
        } cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>graph[i][j];
    }


    floyedwarshall(n);
    printw(n);

}
