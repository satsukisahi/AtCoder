#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

struct edge
{
    ll to;
    ll color;
    ll cost;
    edge() {}
    edge(ll to, ll color, ll cost) : to(to), color(color), cost(cost){};
};

template <typename G>
struct LCA
{
    const ll LOG;
    vector<ll> len;
    vector<ll> dep;
    const G &g;
    vector<vector<ll>> table;

    LCA(const G &g) : g(g), dep(g.size()), len(g.size()), LOG(32 - __builtin_clz(g.size()))
    {
        table.assign(LOG, vector<ll>(g.size(), -1));
    }

    void dfs(ll idx, ll par, ll d, ll l)
    {
        table[0][idx] = par;
        dep[idx] = d;
        len[idx] = l;
        for (auto ed : g[idx])
        {
            if (ed.to != par)
                dfs(ed.to, idx, d + 1, l + ed.cost);
        }
    }

    void build()
    {
        dfs(0, -1, 0, 0);
        for (ll k = 0; k + 1 < LOG; k++)
        {
            for (ll i = 0; i < table[k].size(); i++)
            {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                    table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    ll query(ll u, ll v)
    {
        if (dep[u] > dep[v])
            swap(u, v);
        for (ll i = LOG - 1; i >= 0; i--)
        {
            if (((dep[v] - dep[u]) >> i) & 1)
                v = table[i][v];
        }
        if (u == v)
            return u;
        for (ll i = LOG - 1; i >= 0; i--)
        {
            if (table[i][u] != table[i][v])
            {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};

void dfs(ll x, vector<vector<edge>> &g, bool *see, vector<ll>  *v, vector<ll> *vl, vector<ll>& ans, vector<vector<ll>> &qu, vector<vector<ll>> &tour)
{
    for (auto q : v[x])
    {
        ans[q] -= tour[qu[q][0]][1];
        ans[q] += tour[qu[q][0]][0] * qu[q][1];
    }
    for (auto q : vl[x])
    {
        ans[q] += 2 * tour[qu[q][0]][1];
        ans[q] -= 2 * tour[qu[q][0]][0] * qu[q][1];
    }
    see[x] = 1;
    for (auto p : g[x])
    {
        if (see[p.to])
            continue;
        tour[p.color][0]++;
        tour[p.color][1] += p.cost;
        dfs(p.to, g, see, v, vl, ans, qu, tour);
        tour[p.color][0]--;
        tour[p.color][1] -= p.cost;
    }
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<edge>> g(n);
    rep(i, n - 1)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a - 1].emplace_back(b - 1, c, d);
        g[b - 1].emplace_back(a - 1, c, d);
    }
    LCA<vector<vector<edge>>> lca(g);
    lca.build();

    vector<ll> ans(q);
    vector<ll> v[n];                           //tofromの問い番号
    vector<ll> vl[n];                          //lca頂点の問い番号
    vector<vector<ll>> qu(q, vector<ll>(2));   //色 距離
    vector<vector<ll>> tour(n, vector<ll>(2)); //本数 距離
    bool see[n] = {};
    rep(i, q)
    {
        ll x, y;
        cin >> qu[i][0] >> qu[i][1] >> x >> y;
        x--;
        y--;
        ans[i] = lca.len[x] + lca.len[y] - 2 * lca.len[lca.query(x, y)];
        v[x].push_back(i);
        v[y].push_back(i);
        vl[lca.query(x, y)].push_back(i);
    }

    dfs(0, g, see, v, vl, ans, qu, tour);
    rep(i, q)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
