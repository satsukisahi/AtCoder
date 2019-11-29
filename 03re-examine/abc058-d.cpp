#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m;
cin >> n>>m;
ll x[n] = {};
rep(i, n){
    cin >> x[i];
}
ll y[m] = {};
rep(i, m){
    cin >> y[i];
}
ll sumx=0;
rep(i,n){
    sumx+=i*x[i]-x[i]*(n-i-1);
    sumx%=mo;
}
ll sumy=0;
rep(i,m){
    sumy+=i*y[i]-y[i]*(m-i-1);
    sumy%=mo;
}

ans=(sumx*sumy)%mo;

cout << ans << endl;
return 0;
}