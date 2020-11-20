#include <bits/stdc++.h>
using namespace std;
int tree[1000], arr[1000];
void update(int idx, int x, int n)
{
    while(idx <= n){
        tree[idx]+=x;
        idx +=(idx & -idx);
    }
}
int query(int idx)
{
    int sum=0;
    while(idx > 0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
int main()
{
   int n;
   cin>>n;
   for(int i=1; i<=n; i++){
      cin>>arr[i];
      update(i, arr[i], n);
   }
   cout<<query(3)<<endl;
   cout<<query(5)<<endl;
   cout<<query(3)-query(2)<<endl;
   cout<<query(5)-query(2)<<endl;

}
