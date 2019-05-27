#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
    ll n, q;
    cin >> n >> q;
    ll t[n] = {};
    vector<pair<ll, vector<ll>>> p;
    set<ll> st;

    rep(i, n)
    {
        ll s, t, x;
        cin >> s >> t >> x;
        p.push_back({s - x, {1, x}});
        p.push_back({t - x, {0, x}});
    }
    ll d[q];
    rep(i, q)
    {
        cin >> d[i];
    }
    sort(p.begin(), p.end());
    ll fin = 0;
    ll co = 0;
    while (fin < q)
    {
        if (co==2*n||p[co].first > d[fin])
        {
            if (st.empty())
                cout << -1 << endl;
            else
            {
                auto itr = st.begin();
                cout << *itr << endl;
            }
            fin++;

            continue;
        }
        if (p[co].second[0] == 1)
        {
            st.insert(p[co].second[1]);
            co++;
        }
        else
        {
            st.erase(p[co].second[1]);
            co++;
        }
    }

    return 0;
}