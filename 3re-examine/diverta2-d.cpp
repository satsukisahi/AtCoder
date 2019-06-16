#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll ans1 = 0;
ll dp1[5010] = {};
ll dp2[5010*5010] = {};

int main()
{
ll n;
cin >> n;
ll rate[2][3] = {};
rep(i, 2)
{
    cin >> rate[i][0] >> rate[i][1] >> rate[i][2];
}
dp1[0] = n;
rep(i, n)
{
    rep(j, 3)
    {
        if (i + rate[0][j] < n + 1)
            dp1[i + rate[0][j]] = max(dp1[i + rate[0][j]], dp1[i] - rate[0][j] + rate[1][j]);
    }
}
rep(i, n+1)
{
    ans1 = max(ans1, dp1[i]);
}

dp2[0] = ans1;
rep(i, ans1)
{
    rep(j, 3)
    {
        if (i + rate[1][j] < ans1 + 1)
            dp2[i + rate[1][j]] = max(dp2[i + rate[1][j]], dp2[i] - rate[1][j] + rate[0][j]);
    }
}


rep(i, ans1+1)
{
    ans = max(ans, dp2[i]);
}
cout << ans1 << endl;
cout << ans << endl;
return 0;
}