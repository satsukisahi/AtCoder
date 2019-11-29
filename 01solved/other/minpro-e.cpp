#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;
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
ll n , m ;
cin >> n >> m ;
vector<vector<ll>> v(n, vector<ll>(m,0) );
rep(i,n)rep(j,m)cin >> v[i][j];
vector<bool>see(m,1);
rep(j,m){
  bool a=0;
  ll ind=0;
  rep(i,n){
    if(v[i][j]&&a==0&&see[i]){a=1;ind=i;}
    else if(v[i][j]&&a){
      rep(k,m){
        v[i][k]=(v[i][k]+v[ind][k])%2;
      }
    }
  }
  if(a)see[ind]=0;
}
ll c=0;
rep(i,n){
  ll t=0;
  rep(j,m)t+=v[i][j];
  if(t==0)c++;
}
auto modmul = [](auto... modx) {
  ll res = 1;
  for (auto modx_ : {modx...})
  {
    res *= modx_;
    res %= mo;
  }
  return res;
};
ans=modmul(mypow(2,m-1),mypow(2,n)-mypow(2,c)+mo);
cout << ans << endl;
return 0;
}