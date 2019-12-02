#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
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
const ll MAX = 510000;
const ll MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(ll n, ll k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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
int main()
{
ll n , k ;
cin >> n >> k ;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
COMinit();
vector<ll> fac = factorial(100000);

ll s=0;
rep(i,k+1)s=mod(s+mypow(-1,k-i)*COM(k,i)*mypow(i,n));

//ベル数の直接計算
vector<ll> b={1};
rep(i,k)b.push_back(mod(b.back()+(i%2?1:-1)*mypow(fac[i+1],mo-2)));
ll bb=0;
rep(i,k+1)bb=mod(bb+modmul(mypow(i,n),mypow(fac[i],mo-2),b[k-i]));

//分割数テーブル
vector<vector<ll>> p(5000, vector<ll>(5000,0) );
rep(i,5000)p[i][1]=1;
rep(i,5000)rep(j,4998)p[i][j+2]=mod(p[i][j+1]+(i-j-2>=0?p[i-j-2][j+2]:0));
/* 
https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5
ボール      箱	      入れ方に制限なし 箱の中身は1つ以下 箱の中身は1つ以上
区別できる   区別できる  1            2             3
区別できない  区別できる  4            5             6
区別できる   区別できない 7            8             9
区別できない  区別できない 10          11            12
*/
//1
//cout << mypow(k,n) << endl;
//2
//cout << (COM(k,n)*fac[n])%mo << endl;
//3
//cout << s << endl;
//4
//cout << COM(n+k-1,n) << endl;
//5
//cout << COM(k,n) << endl;
//6
//cout << COM(n-1,k-1) << endl;
//7
//cout << bb << endl;
//8,11
//cout << (n>k?0:1) << endl;
//9 漸化式でもできる
//cout << mod(s*mypow(fac[k],mo-2)) << endl;
//10
//cout << p[n][k] << endl;
//12
//cout << (n-k<0?0:p[n-k][k]) << endl;

return 0;
}