#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll dfs(ll x, vector<vector<ll>> &g, vector<bool> &see,vector<ll> &cl,vector<ll> &ans,vector<ll> &c,vector<stack<ll>> &cn,vector<ll> &par)
{
  ll chi=0;
  //点xに対する処理
  see[x] = 1;
  ll p=-1;
  if(!cn[c[x]].empty())p=cn[c[x]].top();
  cn[c[x]].push(x);
  for (auto r : g[x])
  {
    if (see[r])continue;
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）
    cl[x]=0;
    ll chit=dfs(r, g, see,cl,ans,c,cn,par)+1;
    ans[c[x]]-=(chit+cl[x])*(chit+cl[x]+1)/2;
    //戻る辺に対する処理
    chi+=chit;
  }
  //点xの親に戻る時の処理
  if(p==-1){
    par[c[x]]-=chi+1;
  }
  else{
    cl[p]-=chi+1;
  }
    cn[c[x]].pop();
  return chi;
}

int main()
{
ll n;
cin >> n ;
vector<ll> ans(n,n*(n+1)/2);
vector<ll> cl(n,0);
vector<ll> par(n,n);
vector<stack<ll>> cn(n);
vector<bool> see(n,0);
vector<ll> c(n,0);
rep(i, n){
  ll cc;
  cin >> cc;
  c[i]=cc-1;
}
vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); 
}
dfs(0,g,see,cl,ans,c,cn,par);
rep(i,n)cout << ans[i]-par[i]*(par[i]+1)/2 << endl;
return 0;
}