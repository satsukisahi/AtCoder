#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll dfs(ll p){
    v[p][0]=
}
int main()
{
ll n;
cin >> n;
set<ll> G[n];
vector<vector<ll>> v(n, vector<ll>(3,-1) );


rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].insert(b-1);
    G[b-1].insert(a-1);
}
ans=dfs(0);

cout << ans << endl;
return 0;
}
