#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
string ans[2]={"Bob","Alice"};

int main()
{
ll n;
cin >> n ;
vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); 
}
ll root=0;
vector<vector<ll>> child(n);
vector<ll> par(n);
vector<ll> gu(n);
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
    for(auto r:child[par[p]]){
      gu[par[p]]^=(gu[r]+1);
    }
  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    //child[par[p]]に子の値が入ってる
    for(auto r:child[par[p]]){
      gu[par[p]]^=(gu[r]+1);
    }
    qq.push(par[p]);
  }
}
cout << ans[(bool)gu[0]] << endl;
return 0;
}