#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans[100010][2] = {};

int main()
{
ll n;
cin >> n;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}
sort(t,t+n);
ll sum=0;
ll ma=t[n-1];
ll mi=t[0];
if(n==2){ans[0][0]=ma;ans[0][1]=mi;ma-=mi;}
else{
rep(i,n-2){
    if(t[i+1]>0){ans[i][0]=mi;ans[i][1]=t[i+1];mi-=t[i+1];}
    else {ans[i][0]=ma;ans[i][1]=t[i+1];ma-=t[i+1];}
}
{ans[n-2][0]=ma;ans[n-2][1]=mi;ma-=mi;}
}
cout << ma << endl;
//2次元配列の中身を見る

for (int i = 0; i < n-1; ++i){
for (int j = 0; j < 2; ++j) {
    cout << ans[i][j] << " ";
}cout  << endl;}
return 0;
}