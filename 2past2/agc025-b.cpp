#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;
const int MAX = 510000;
const int MOD = 998244353;
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
struct Timer {
  chrono::high_resolution_clock::time_point st;

  Timer() { reset(); }

  void reset() {
    st = chrono::high_resolution_clock::now();
  }

  chrono::milliseconds::rep elapsed() {
    auto ed = chrono::high_resolution_clock::now();
    return chrono::duration_cast< chrono::milliseconds >(ed - st).count();
  }
};
int main()
{
Timer tim;
ll n , a , b , k  ;
cin >> n >> a >> b >> k ;
tim.reset();
COMinit();
rep(i,n+1){
  if((k-a*i)%b==0&&(k-a*i)/b>=0){
    ll re=(k-a*i)/b;
    ll bl=i;
    ans+=COM(n,re)*COM(n,bl);
    ans%=mo;
  }
}

cout << ans << endl;
cout << tim.elapsed() << endl;
return 0;
}
