#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
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
vector<ll> v(n+1);
v[0]=1;
rep(i,n){
  v[i+1]=mod(v[i]*2);
}

vector<vector<ll>> child(n);
vector<vector<ll>> num(n);
vector<ll> par(n);
vector<ll> sum(n);
queue<ll> q;
queue<ll> qq;
ll root=0;
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
  num[par[p]].push_back(sum[p]+1);
  sum[par[p]]+=sum[p]+1;
  //根の時は例外処理
  if(child[par[p]].size()==g[par[p]].size()){
    //child[par[p]]に子の値が入ってる
  }
  //全ての葉が親に追加し終わった
  if(child[par[p]].size()==g[par[p]].size()-1 && par[p]!=root){
    //child[par[p]]に子の値が入ってる
    qq.push(par[p]);
  }
}
rep(i,n){
  ll t=0;
  for(auto r:num[i]){
    t=mod(t+v[r]-1);
  }
  t=mod(t+v[n-sum[i]-1]);
  ans=mod(ans+v[n-1]-t);
}
cout << mod(ans*mypow(v[n],mo-2)) << endl;
return 0;
}