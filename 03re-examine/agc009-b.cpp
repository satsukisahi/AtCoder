#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<vector<ll>> g(n);

rep(i, n-1){
  ll a;
  cin >> a;
  g[i+1].push_back(a-1);
  g[a-1].push_back(i+1);
}
vector<vector<ll>> st(n);
vector<ll> par(n);
vector<ll> ans(n);
queue<ll> q;
queue<ll> qq;

q.push(0);
par[0]=-1;
while(!q.empty()){
  ll p=q.front();
  q.pop();
  if(g[p].size()==1 && p!=0){qq.push(p);}
  for(auto r:g[p]){
    if(r==par[p])continue;
    par[r]=p;
    q.push(r);
  }
}
while(!qq.empty()){
  ll p=qq.front();
  qq.pop();
  st[par[p]].push_back(ans[p]+1);
  if(st[par[p]].size()==g[par[p]].size()){
    sort(st[par[p]].rbegin(),st[par[p]].rend());
    rep(i,st[par[p]].size())st[par[p]][i]+=i;
    ans[par[p]]=*max_element(st[par[p]].begin(),st[par[p]].end());
  }
  if(st[par[p]].size()==g[par[p]].size()-1 && par[p]!=0){
    sort(st[par[p]].rbegin(),st[par[p]].rend());
    rep(i,st[par[p]].size())st[par[p]][i]+=i;
    ans[par[p]]=*max_element(st[par[p]].begin(),st[par[p]].end());
    qq.push(par[p]);
  }
}
cout << ans[0] << endl;
return 0;
}