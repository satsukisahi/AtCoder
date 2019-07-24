#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807

int main()
{
ll kai = INF;
ll r, g, b;
cin >> r >> g >> b;
ll kaia[3];

ll rr = -100, gg = -1, bb = 99;
rep(i, 600) rep(j, 1200) rep(k, 1200)
{
    rr = i - 600;
    gg = j - 600;
    bb = k - 300;
    if (!(rr < gg && gg < bb))
        continue;
    if (gg - rr < r || bb - gg < g)
        continue;
    ll ans = 0;

    if (-100 - rr > r || -100 < rr)
        ans += (abs(rr + 100) + abs(rr + r + 99)) * r / 2;
    else
        ans += abs(rr + 100) * (abs(rr + 100) + 1) / 2 + abs(rr + r + 100 - 1) * (abs(rr + r + 100 - 1) + 1) / 2;
    //cout << ans << endl;

    if (-gg > g || 0 < gg)
        ans += (abs(gg) + abs(gg + g-1)) * g / 2;
    else
        ans += abs(gg) * (abs(gg) + 1) / 2 + abs(gg + g - 1) * (abs(gg + g - 1) + 1) / 2;
    //cout << ans << endl;

    if (100 - bb > b || 100 < bb)
        ans += (abs(bb - 100) + abs(bb + b - 101)) * b / 2;
    else
        ans += abs(bb + (-100)) * (abs(bb + (-100)) + 1) / 2 + abs(bb + b + (-100) - 1) * (abs(bb + b + (-100) - 1) + 1) / 2;
    //cout << ans << endl;
    if (kai > ans)
    {
        kai = ans;
        kaia[0] = rr;
        kaia[1] = gg;
        kaia[2] = bb;
    }
}

cout << kai << endl;
//cout << kaia[0] << " " << kaia[1] << " " << kaia[2] << endl;
return 0;
}
