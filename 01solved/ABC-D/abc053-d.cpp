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
ll n;
cin >> n;
set<ll> s;

rep(i, n){
    ll a;
    cin >> a;
    s.insert(a);
}

ans=s.size();
if(ans%2==0)ans--;
cout << ans << endl;
return 0;
}