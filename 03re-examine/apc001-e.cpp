#pragma GCC target ("avx512f")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n;
cin >> n ;
vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a].push_back(b);
  g[b ].push_back(a);
}
ll root;
rep(i,n+1){
  if(i==n){
    cout << 1 << endl;
    return 0;
  }
  if(g[i].size()>2){root=i;break;}
}
vector<vector<ll>> child(n);
vector<ll> par(n);
vector<bool> k(n);
queue<ll> q;
queue<ll> qq;
q.push(root);
par[root]=-1;
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
  //根の時は例外処理
  if(child[par[p]].size()==g[par[p]].size()){
    //child[par[p]]に子の値が入ってる
    ll cnt=0;
    for(auto r:child[par[p]]){
      if(k[r])cnt++;
    }
    if(cnt<child[par[p]].size())ans+=child[par[p]].size()-1-cnt;
  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    //child[par[p]]に子の値が入ってる
    ll cnt=0;
    for(auto r:child[par[p]]){
      if(k[r]){
        cnt++;
        k[par[r]]=1;
      }
    }
    if(cnt<child[par[p]].size())ans+=child[par[p]].size()-1-cnt;
    if(child[par[p]].size()-1-cnt>0)k[par[p]]=1;
    qq.push(par[p]);
  }
}
cout << ans << endl;
return 0;
}