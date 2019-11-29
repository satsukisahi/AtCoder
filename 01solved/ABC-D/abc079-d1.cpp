#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = 0;
ll d[10][10];
ll ko[10] = {};

int main()
{
    ll h, w;
    cin >> h >> w;
    rep(i, 10) rep(j, 10)
    {
        cin >> d[i][j];
    }
    rep(i, h) rep(j, w)
    {
        ll te;
        cin >> te;
        if (te >= 0)
            ko[te]++;
    }
    
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        rep(i,10){
        ans+=d[i][1]*ko[i];
    }
    cout << ans << endl;
    return 0;
}