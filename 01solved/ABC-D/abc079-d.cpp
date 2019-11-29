#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = 0;
ll ch[10][10];
ll ko[10] = {};

int main()
{
    ll h, w;
    cin >> h >> w;
    rep(i, 10) rep(j, 10)
    {
        cin >> ch[i][j];
    }
    rep(i, h) rep(j, w)
    {
        ll te;
        cin >> te;
        if (te >= 0)
            ko[te]++;
    }
    ll cost[10] = {};
    queue<pair<int, int>> q;
    rep(k, 10)
    {
        ll minn = ch[k][1];
        rep(i, 10)
        {
            if (i != 1 && i != k)
                q.push({i, ch[k][i]});
        }
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == 1 && minn > p.second)
            {
                minn = p.second;
            }
            if (p.second < minn)
            {
                rep(i, 10)
                {
                    if (i != p.first)
                        q.push({i, p.second + ch[p.first][i]});
                }
            }
        }
        cost[k] = minn;
    }
    rep(i,10){
        ans+=cost[i]*ko[i];
    }
    cout << ans << endl;
    return 0;
}