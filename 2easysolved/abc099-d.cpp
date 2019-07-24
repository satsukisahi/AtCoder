#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n, c;
cin >> n >> c;
ll d[c][c] = {};
rep(i, c) rep(j, c)
{
    cin >> d[i][j];
}
vector<ll> v[3];
rep(i, n) rep(j, n)
{
    ll a;
    cin >> a;
    v[(i + j + 2) % 3].push_back(a);
}

vector<vector<ll>> chh(3, vector<ll>(c,0) );
rep(i, 3) rep(j, c)
{
    rep(k, v[i].size())
    {
        chh[i][j] += d[v[i][k]-1][j];
    }
}
rep(i, c) rep(j, c) rep(k, c)
{
    if (i == j || j == k || k == i)
        continue;
    ans = min(ans, chh[0][i] + chh[1][j] + chh[2][k]);
}

cout << ans << endl;
return 0;
}
