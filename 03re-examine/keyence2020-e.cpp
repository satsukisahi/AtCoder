#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
struct edge
{
  ll to;
  ll cost,num;
  edge() {}
  edge(ll to, ll cost,ll num) : to(to), cost(cost),num(num){};
};
int main()
{
ll n, m;
cin >> n >> m;
vector<vector<edge>> g(n);
vector<vector<edge>> gg(n);
vector<ll> v(n);
rep(i, n){
  cin >> v[i];
}
rep(i, m)
{
  ll a, b;
  cin >> a >> b ;
  g[a - 1].emplace_back(b - 1, -1,i);
  g[b - 1].emplace_back(a - 1, -1,i);
}
rep(i,n){
  bool ok=0;
  for(auto r:g[i])if(v[i]>=v[r.to])ok=1;
  if(!ok){
    cout << -1 << endl;
    return 0;
  }
}
vector<bool> s(n,0);
vector<bool> see(n,0);
vector<ll> ans(m,1000000000);
rep(i,n){
  if(see[i])continue;
  ll mi=1LL<<40;
  for(auto r:g[i])mi=min(mi,v[r.to]);
  for(auto r:g[i])if(mi==v[r.to]){
    ans[r.num]=v[i];
    gg[r.to].emplace_back(i, -1,i);
    gg[i].emplace_back(r.to, -1,i);
    break;}
}
rep(i,n){
  if(see[i])continue;
  queue<ll> q;
  q.push(i);
  while(!q.empty()){
    ll p=q.front();
    see[p]=1;
    q.pop();
    for(auto r:gg[p]){
      if(!see[r.to]){
        s[r.to]=!s[p];
        q.push(r.to);
      }
    }
  }
}
string ss="";
rep(i,n){
  if(s[i])ss+='B';
  else ss+='W';
}
cout << ss << endl;
for(auto r:ans)cout << r << endl;
return 0;
}