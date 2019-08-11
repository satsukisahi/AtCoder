#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans[3000] = {};
ll mo;
const int MAX = 5100;
int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
ll p ;
cin >> p ;
mo=p;
MOD=p;
vector<ll> a(p);
rep(i, p){
  cin >> a[i];
}
auto mod = [](ll modx){modx%=mo;modx+=mo;modx%=mo;return modx;};
COMinit();
rep(i,p){
  if(a[i]==1){
    ans[0]+=1;
    ll te=1;
    rep(j,p){
      ans[p-j-1]-=COM(p-1,j)*te*(j%2?-1:1);
      te=te*i%mo;
    }
  }
}
rep(i,p)
cout <<  mod(ans[i]) << " ";
cout << endl;
return 0;
}
