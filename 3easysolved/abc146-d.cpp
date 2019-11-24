#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
int main()
{
ll n;
cin >> n ;
vector<vector<edge>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b ;
  g[a - 1].emplace_back(b - 1, i);
  g[b - 1].emplace_back(a - 1, i); //無向辺
}
ll c=0;
vector<ll> ans(n-1);
vector<ll> see(n);
queue<ll> q;
see[0]=1;
ll tt=1;
for(auto r:g[0]){
  ans[r.cost]=tt;
  see[r.to]=tt;
  tt++;
  q.push(r.to);
}
while(!q.empty()){
  auto p=q.front();
  q.pop();
  ll t=1;
  for(auto r:g[p]){
    if(see[r.to]!=0)continue;
    if(t==see[p])t++;
    ans[r.cost]=t;
    see[r.to]=t;
    t++;
    q.push(r.to);
  }
}
c=*max_element(ans.begin(),ans.end());
cout << c << endl;
rep(i,n-1)cout << ans[i] << endl;

return 0;
}