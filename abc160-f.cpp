#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
ll mypow(ll a, ll b)
{
  ll res = 1;
  a %= mo;
  while (b)
  {
    if (b & 1)
      res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
vector<ll> factorial(ll n)
{
  vector<ll> fac;
  fac.push_back(1);
  for (ll i = 1; i < n + 10; i++)
  {
    fac.push_back((fac[i - 1] * i) % mo);
  }
  return fac;
}
auto modmul = [](auto... modx) {
  ll res = 1;
  for (auto modx_ : {modx...})
  {
    res *= modx_;
    res %= mo;
    res += mo;
    res %= mo;
  }
  return res;
};
int main()
{
ll n ;
cin >> n ;
vector<ll> ans(n,0);

vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); 
}
vector<ll> fac = factorial(n);

vector<vector<ll>> child(n);
vector<ll> par(n);
vector<ll> k(n,1);
vector<ll> kk(n,1);
ll root=0;
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
    ll te=1,nu=1;
    for(auto r:child[par[p]]){
      te*=k[r];
      te%=mo;
      nu+=kk[r];
    }
    kk[par[p]]=nu;
    k[par[p]]=(nu*te)%mo;
  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    ll te=1,nu=1;
    for(auto r:child[par[p]]){
      te*=k[r];
      te%=mo;
      nu+=kk[r];
    }
    kk[par[p]]=nu;
    k[par[p]]=(nu*te)%mo;
    qq.push(par[p]);
  }
}

ll tee=1,nuu=1;
for(auto r:g[root]){
  tee*=k[r];
  tee%=mo;
  nuu+=kk[r];
}
kk[root]=nuu;
k[root]=(nuu*tee)%mo;

vector<ll> t(n,1);
vector<ll> tt(n,1);

vector<bool> see(n);
par[root]=-1;
see[root]=1;
q.push(root);
while(!q.empty()){
  auto p=q.front();
  q.pop();
  ll te=1;
  for(auto r:g[p]){
    if(par[p]==r){te*=t[p];te%=mo;}
    else {te*=k[r];te%=mo;}
  }
  ans[p]=(fac[n-1]*mypow(te,mo-2))%mo;
  for(auto r:g[p]){
    if(see[r]!=0)continue;
    par[r]=p;
    see[r]=1;
    q.push(r);
    tt[r]=n-kk[r];
    t[r]=modmul(k[p],tt[r],mypow(kk[p],mo-2),mypow(k[r],mo-2),t[p]);
  }
}
for(auto r:ans)cout << r << endl;
return 0;
}