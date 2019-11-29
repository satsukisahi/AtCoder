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
ll n,a,b;
cin >> n>>a>>b;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}
rep(i,n-1){
    if((t[i+1]-t[i])*a>b)ans+=b;
    else ans+=(t[i+1]-t[i])*a;
}


cout << ans << endl;
return 0;
}
