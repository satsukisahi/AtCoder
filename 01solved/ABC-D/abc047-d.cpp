#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,k;
cin >> n>>k;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}
ll tt[n] = {};
ll ma=t[n-1];
rep(i,n){
    if(ma<t[n-i-1])ma=t[n-i-1];
    tt[n-i-1]=ma-t[n-i-1];
}
ma=0;
rep(i,n){
    if(ma<tt[i])ma=tt[i];
}
rep(i,n){
    if(ma==tt[i])ans++;
}



cout << ans << endl;
return 0;
}
