#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;
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
int main()
{
struct edge {
    ll to;
    ll cost;
    edge() {}
    edge(ll to, ll cost) : to(to), cost(cost) {};
};

ll n;
cin >> n  ;
vector<vector<edge>> G(n);
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].emplace_back(b-1, 1);
    G[b-1].emplace_back(a-1, 1); //無向辺
}

LCA<vector<vector<edge>>> lca(G);
lca.build();
ll q;
cin >> q ;
rep(i,q){
    ll a,b;
    cin >> a >> b ;
    a--;b--;
    cout << lca.len[a]+lca.len[b] - 2 * lca.len[lca.query(a, b)]+1 <<endl;
}


return 0;
}
