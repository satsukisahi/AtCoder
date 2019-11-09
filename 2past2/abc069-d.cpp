#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll h,w,n;
cin >> h>>w>>n;
ll t[n] = {};
rep(i, n)
{
    cin >> t[i];
}
ll gr[h][w];
ll co=0;
rep(i,n)rep(j,t[i]){
    gr[co/w][co%w]=i;
    co++;
}
rep(i,h){rep(j,w){
    if(i%2){cout << gr[i][j]+1 <<' ';}
    else{cout << gr[i][w-j-1]+1 <<' ';}
}
cout  << endl;
}

return 0;
}