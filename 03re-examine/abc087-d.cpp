#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;

struct edge {
    int to, cost;
};
vector<edge> G[200010];
bool vis[100010];
int d[100010];

bool dfs(int v,int dist){
    if(vis[v]){
        if (d[v] != dist) {
            return true;
        }
        else{
            return false;
        }
    }
    vis[v]=true;
    d[v]=dist;
    for(int i=0;i<(int)G[v].size();i++){
        if (dfs(G[v][i].to, d[v] + G[v][i].cost)) {
            return true;//その頂点における判定で一つでも矛盾があれば、全てtrueを返して強制終了。
        }
        //何も矛盾が無ければ次のリストを見る。
    }
    return false;//連結している頂点が最後まで探索できたという証。
}



int main()
{ 
ll n,m;
cin >> n>>m; 
for (int i = 0; i < m; i++) {
    int L, R, D;
    cin >> L >> R >> D;
    L--; R--;
    G[L].push_back({ R,D });
    G[R].push_back({ L,-D });
}
for(int i=0;i<n;i++){
    if(!vis[i]&&dfs(i,0)){
        cout<<"No"<<endl;
        return 0;
    }
}

cout << "Yes" << endl;
return 0;
} 