#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 922337203685477;
ll ans = INF;
ll d[210][210] = {};

int main()
{
    ll n, m, r;
    cin >> n >> m >> r;
    ll rr[r] = {};
    rep(i, r)
    {
        cin >> rr[i];
        rr[i]--;
    }
    sort(rr, rr + r);
    rep(i, n) rep(j, n)
    {
        //if (i != j)
            d[i][j] = INF;
    }
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        d[a - 1][b - 1] = c;
        d[b - 1][a - 1] = c;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    bool a = 1;
    ll array[8]={0,1,2,3,4,5,6,7};
    while (a)
    {

        ll temp = 0;
        rep(i, r - 1)
        {
            temp += d[rr[array[i]]][rr[array[i + 1]]];
        }
        ans = min(ans, temp);
        a = next_permutation(array, array + r);
    }

    cout << ans << endl;
    return 0;
}