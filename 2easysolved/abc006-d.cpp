#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807


int main()
{
ll n;
cin >> n;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}
vector<ll> v(n,INF);
rep(i,n){
    auto itr = lower_bound(v.begin(),v.end(), t[i]);
    *itr=t[i];
}
ll a=lower_bound(v.begin(),v.end(), INF-1)-v.begin();
cout << n-a << endl;
return 0;
}
