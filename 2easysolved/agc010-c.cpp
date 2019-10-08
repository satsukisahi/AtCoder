#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<vector<ll>> g(n);
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
}
if(n==2){
  if(a[0]==a[1])cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
ll root;
vector<vector<ll>> st(n);
vector<ll> par(n);
queue<ll> q;
queue<ll> qq;

rep(i,n)if(g[i].size()>1){root=i;break;}
q.push(root);
par[root]=-1;
while(!q.empty()){
  ll p=q.front();
  q.pop();
  if(g[p].size()==1)qq.push(p);
  for(auto r:g[p]){
    if(r==par[p])continue;
    par[r]=p;
    q.push(r);
  }
}
while(!qq.empty()){
  ll p=qq.front();
  qq.pop();
  st[par[p]].push_back(a[p]);
  if(st[par[p]].size()==g[par[p]].size()){
    ll sum=accumulate(st[par[p]].begin(),st[par[p]].end(),0);
    if(sum%2==0 && *max_element(st[par[p]].begin(),st[par[p]].end()) <=sum/2 && a[par[p]]==sum/2 )cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
  }
  if(st[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    ll sum=accumulate(st[par[p]].begin(),st[par[p]].end(),0);
    if(max(*max_element(st[par[p]].begin(),st[par[p]].end()),(sum+1)/2)<=a[par[p]] && a[par[p]]<=sum ){
      a[par[p]]=a[par[p]]*2-sum;
    }
    else{
      cout << "NO" << endl;
      return 0;
    }
    qq.push(par[p]);
  }
}
return 0;
}