#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<vector<ll>> g(n);
rep(i,n-1){
  ll p ;
  cin >> p ;
  g[i+1].push_back(p-1);
  g[p-1].push_back(i+1);
}
vector<pair<ll,ll>> x(n);
rep(i, n){
  cin >> x[i].first;
}
ll root=0;
vector<vector<ll>> child(n);
vector<ll> par(n);
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
    ll sum=0;
    for(auto r:child[par[p]]){
      sum+=x[r].first+x[r].second;
    }
    bitset<5001> bit;
    bit[0]=1;
    for(auto r:child[par[p]]){
      bit=(bit<<x[r].first)|(bit<<x[r].second);
    }
    ll mx=-1;
    rep(i,x[par[p]].first+1){
      if(bit[i])mx=i;
    }
    if(mx==-1){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    else{
      x[par[p]].second=sum-mx;
    }
  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    //child[par[p]]に子の値が入ってる
    ll sum=0;
    for(auto r:child[par[p]]){
      sum+=x[r].first+x[r].second;
    }
    bitset<5001> bit;
    bit[0]=1;
    for(auto r:child[par[p]]){
      bit=(bit<<x[r].first)|(bit<<x[r].second);
    }
    ll mx=-1;
    rep(i,x[par[p]].first+1){
      if(bit[i])mx=i;
    }
    if(mx==-1){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    else{
      x[par[p]].second=sum-mx;
    }
    qq.push(par[p]);
  }
}
cout << "POSSIBLE" << endl;
return 0;
}