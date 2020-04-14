#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mi = -(1LL << 60); //MAX 9223372036854775807

int main()
{
ll n;
cin >> n ;
vector<vector<ll>> g(n);
//多重辺がないならsetでもよい（辺を消去したいときなど）この場合はinsert
//set<ll> g[n];
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
}
vector<ll> v(n,mi);
ll k ;
cin >> k ;
rep(i,k){
  ll a , b ;
  cin >> a >> b ;
  v[a-1]=b;
}
{
vector<ll> par(n);
vector<ll> dist(n);
vector<bool> see(n);
queue<ll> q;
par[0]=-1;
see[0]=1;
q.push(0);
while(!q.empty()){
  auto p=q.front();
  q.pop();
  for(auto r:g[p]){
    if(see[r]!=0)continue;
    par[r]=p;
    see[r]=1;
    dist[r]=dist[p]+1;
    q.push(r);
  }
}
bool kk;
rep(i,n){
  if(v[i]!=mi){kk=(v[i]%2)^(dist[i]%2);break;}
}
rep(i,n){
  if(v[i]!=mi&&kk!=(v[i]%2)^(dist[i]%2)){
    cout << "No" << endl;
    return 0;
  }
}
}
ll root=0;
vector<vector<ll>> child(n);
vector<vector<pair<ll,ll>>> cp(n);
vector<pair<ll,ll>> vp(n);
vector<ll> par(n);
queue<ll> q;
queue<ll> qq;
q.push(root);
par[root]=-1;
rep(i,n){
  if(v[i]!=mi)vp[i]={v[i],v[i]};
  else vp[i]={mi,mi};
}
//親の定義と葉を見つける
while(!q.empty()){
  ll p=q.front();
  q.pop();
  if(g[p].size()==1 && p!=root){qq.push(p);}
  for(auto r:g[p]){
    if(r==par[p])continue;
    par[r]=p;
    q.push(r);
  }
}
while(!qq.empty()){
  ll p=qq.front();
  qq.pop();
  child[par[p]].push_back(p);//親に値を追加する
  cp[par[p]].push_back(vp[p]);
  //根の時は例外処理
  if(child[par[p]].size()==g[par[p]].size()){
    //child[par[p]]に子の値が入ってる
    pair<ll,ll> r={mi,1LL<<50};
    for(auto rr:cp[par[p]]){
      if(rr.first==mi)continue;
      r.first=max(r.first,rr.first-1);
      r.second=min(r.second,rr.second+1);
    }
    if(r.first>r.second){
      cout << "No" << endl;return 0;
    }
    if(vp[par[p]].first!=mi&&(r.first>vp[par[p]].first||r.second<vp[par[p]].second)){
      cout << "No" << endl;return 0;
    }
    if(vp[par[p]].first!=mi){r=vp[par[p]];}
    if(r.first!=mi)vp[par[p]]=r;
  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    //child[par[p]]に子の値が入ってる
    pair<ll,ll> r={mi,1LL<<50};
    for(auto rr:cp[par[p]]){
      if(rr.first==mi)continue;
      r.first=max(r.first,rr.first-1);
      r.second=min(r.second,rr.second+1);
    }
    if(r.first>r.second){
      cout << "No" << endl;return 0;
    }
    if(vp[par[p]].first!=mi&&(r.first>vp[par[p]].first||r.second<vp[par[p]].second)){
      cout << "No" << endl;return 0;
    }
    if(vp[par[p]].first!=mi){r=vp[par[p]];}
    if(r.first!=mi)vp[par[p]]=r;
    qq.push(par[p]);
  }
}
{
vector<bool> see(n);
queue<ll> q;
see[0]=1;
q.push(0);
while(!q.empty()){
  auto p=q.front();
  if(p==0)v[p]=vp[p].second;
  else v[p]=v[par[p]]+1;
  if(v[p]>vp[p].second)v[p]-=2;
  if(v[p]==mi)v[p]=v[par[p]]+1;
  if(p!=0&&abs(v[p]-v[par[p]])!=1){
    assert(0);
  }
  q.pop();
  for(auto r:g[p]){
    if(see[r]!=0)continue;
    see[r]=1;
    q.push(r);
  }
}
}
cout << "Yes" << endl;
rep(i,n)cout << v[i] << endl;
return 0;
}