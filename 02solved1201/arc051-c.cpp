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
int main()
{
ll n , a , b ;
cin >> n >> a >> b ;
vector<ll> v(n);
rep(i, n){
  cin >> v[i];
}
sort(v.begin(),v.end());
if(a==1){
  for(auto an:v)cout << an << endl;
  return 0;
}
ll cnt=0;
rep(i,b){
  v[0]*=a;
  cnt++;
  if(v[0]>v[n-1])break;
  sort(v.begin(),v.end());
}
sort(v.begin(),v.end());
b-=cnt;
vector<ll> ans;
for (ll i = b%n; i < n; i++)
{
  ans.push_back(v[i]);
}
for (ll i = 0; i < b%n; i++)
{
  ans.push_back(mod(mod(v[i])*a));
}
rep(i,n){
  ans[i]=mod(mod(ans[i])*mypow(a,b/n));
}

for(auto an:ans)cout << an << endl;
return 0;
}