#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
vector<ll> divisor(ll n)
{
  vector<ll> div;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      div.push_back(i);
      if (n / i != i)
        div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return div;
}
int main()
{
ll n ;
cin >> n ;
auto v=divisor(n);
for(auto r:v){
  if(r==1)continue;
  if(r==n)continue;
  ll nn=n;
  while(nn>=r&&nn%r==0){
    nn/=r;
  }
  nn%=r;
  if(nn==1)ans++;
}
auto vv=divisor(n-1);
ans+=vv.size()-1;

cout << ans+1 << endl;
return 0;
}