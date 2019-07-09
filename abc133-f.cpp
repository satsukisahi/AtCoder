#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807

struct edge {
    ll to;
    ll color;
    ll cost;
    edge() {}
    edge(ll to, ll color,ll cost) : to(to), color(color),cost(cost) {};
};
vector<edge> G[100000];
class LCA {
public:
    ll V, logV;
    vector<ll> depth, len;
    vector<vector<ll> > parent;
    
    LCA(ll V) {
        this->V = V;
        logV = 0;
        while (V > (1LL<<logV)) logV++;
        this->depth = vector<ll>(V);
        this->len = vector<ll>(V);
        this->parent = vector<vector<ll> >(logV, vector<ll>(V));
    }
    
    void init(ll v, ll par, ll d, ll l) {
        depth[v] = d;
        parent[0][v] = par;
        len[v] = l;
        for (ll i = 0; i < (ll)G[v].size(); i++) {
            ll w = G[v][i].to;
            ll lc = G[v][i].cost;
            if (w == par) continue;
            init(w, v, d+1, lc + l);
        }
    }
    
    void build() {
        for (ll k = 0; k + 1 < logV; k++) {
            for (ll v = 0; v < V; v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
    
    ll query(ll u, ll v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (ll k = 0; k < logV; k++) {
            if ((depth[v] - depth[u]) >> k & 1)
                v = parent[k][v];
        }
        if (u == v) return u;
        
        for (ll k = logV-1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main()
{
ios::sync_with_stdio(false);cin.tie(nullptr);
ll n,q;
cin >> n >> q ;
rep(i, n-1)
{
    ll a,b,c,d;
    cin >> a>>b>>c>>d;
    G[a-1].emplace_back(b-1, c,d);
    G[b-1].emplace_back(a-1, c,d); 
}
LCA lca(n);
lca.init(0, -1, 0, 0);
lca.build();
ll ans[q] = {};
vector<vector<ll>> qu(q, vector<ll>(5,0) );//0番号 1色 2変更する数字 34tofrom
vector<ll> Q[n];//頂点に問い番号を付与 1-indexed
ll tour[n][2]={}; //0和 1本数
rep(i, q)
{
    qu[i][0]=i+1;
    rep(j,4)cin >> qu[i][j+1];
    --qu[i][3];--qu[i][4];
    ll z = lca.query(qu[i][3], qu[i][4]);
    ll ret = lca.len[qu[i][3]] + lca.len[qu[i][4]] - 2 * lca.len[z];
    ans[i]=ret;
    Q[qu[i][3]].push_back(qu[i][0]);
    Q[qu[i][4]].push_back(qu[i][0]);
    Q[z].push_back(-qu[i][0]);
}
ll next=0;
bool se[n]={};//訪れた子かどうか
ll back[n]={};//頂点へ戻った回数
edge par[n];
deque<edge> deq;

//辺に対してオイラーツアー
while(back[0]!=G[0].size()){
    rep(i,Q[next].size()){
        if(Q[next][i]>0){
            ans[Q[next][i]-1]+=tour[qu[Q[next][i]-1][1]][1]*qu[Q[next][i]-1][2];
            ans[Q[next][i]-1]-=tour[qu[Q[next][i]-1][1]][0];
        }
        else{
            ans[-Q[next][i]-1]-=2*(tour[qu[-Q[next][i]-1][1]][1]*qu[-Q[next][i]-1][2]);
            ans[-Q[next][i]-1]+=2*(tour[qu[-Q[next][i]-1][1]][0]);
        }
    }
    //Q[next].clear();
    if(!se[next]){ //初めて訪れた
        bool nochild=1;
        se[next]=1;
        rep(i,G[next].size()){
            if(!se[G[next][i].to]){
                deq.push_back(G[next][i]);
                nochild=0;
            }
        }

        if(nochild){
            //前の点へ戻る
            edge ed=par[next];
            tour[ed.color][0]-=ed.cost;
            tour[ed.color][1]--;
            next=ed.to;
            back[next]++;
        }
        else{
            //deqから取り出した点へ行く
            edge ed=deq.back();
            deq.pop_back();
            par[ed.to]=ed;
            par[ed.to].to=next;
            tour[ed.color][0]+=ed.cost;
            tour[ed.color][1]++;
            next=ed.to;
        }
    }
    else{ //二回目以降
        if(next!=0&&G[next].size()==back[next]+1){
            //前の点へ戻る
            edge ed=par[next];
            tour[ed.color][0]-=ed.cost;
            tour[ed.color][1]--;
            next=ed.to;
            back[next]++;
        }
        else{
            //deqから取り出した点へ行く
            edge ed=deq.back();
            deq.pop_back();
            par[ed.to]=ed;
            par[ed.to].to=next;
            tour[ed.color][0]+=ed.cost;
            tour[ed.color][1]++;
            next=ed.to;
        }
    }

}

for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
}
return 0;
}
