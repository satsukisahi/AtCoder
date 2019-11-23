#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

template <typename flow_t>
struct FordFulkerson
{
    struct edge
    {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
    };

    vector<vector<edge>> graph;
    vector<int> used;
    const flow_t INF;
    int timestamp;

    FordFulkerson(int n) : INF(numeric_limits<flow_t>::max()), timestamp(0)
    {
        graph.resize(n);
        used.assign(n, -1);
    }

    void add_edge(int from, int to, flow_t cap)
    {
        graph[from].emplace_back((edge){to, cap, (int)graph[to].size(), false});
        graph[to].emplace_back((edge){from, 0, (int)graph[from].size() - 1, true});
    }

    flow_t dfs(int idx, const int t, flow_t flow)
    {
        if (idx == t)
            return flow;
        used[idx] = timestamp;
        for (auto &e : graph[idx])
        {
            if (e.cap > 0 && used[e.to] != timestamp)
            {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t)
    {
        flow_t flow = 0;
        for (flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++)
        {
            flow += f;
        }
        return flow;
    }

    void output()
    {
        for (int i = 0; i < graph.size(); i++)
        {
            for (auto &e : graph[i])
            {
                if (e.isrev)
                    continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

int main()
{
ll n,g,e;
cin >> n>>g>>e;
ll p[g] = {};
FordFulkerson< int > G(n+1);
rep(i, g){
    cin >> p[i];
    G.add_edge(p[i],n,1);
}
rep(i,e){
    ll a,b;
    cin >> a >> b ;
    G.add_edge(a,b,1);
    G.add_edge(b,a,1);
}

cout << G.max_flow(0,n) << endl;
return 0;
}