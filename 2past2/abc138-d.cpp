#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans[200020] = {};
ll te=0;
void dfs(ll x, vector<vector<ll>> &g, bool *see,ll *po)
{
  //点xに対する処理
  see[x] = 1;
  te+=po[x];
  ans[x]=te;

  for (auto p : g[x])
  {
    if (see[p])
        continue;
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）

    dfs(p, g, see,po);
    //戻る辺に対する処理
  }
  te-=po[x];
}
int main()
{
ll n,q;
cin >> n >> q ;
vector<vector<ll>> g(n);
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1); //無向辺
}
ll po[n]={};
bool see[n]={};
rep(i,q){
  ll p , x ;
  cin >> p >> x ;
  po[p-1]+=x;
}

dfs(0,g,see,po);
rep(i,n){
  cout << ans[i] << " ";
  
}
cout << endl;
return 0;
}
