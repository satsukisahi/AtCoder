#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> a(n);
vector<ll> b(n);
rep(i, n){
  cin >> a[i] >> b[i];
}
vector<ll> z;
ll mask=0;
if(k==0){
  rep(i,n)if(a[i]==0)ans+=b[i];
  cout << ans << endl;
  return 0;
}
for(ll i=63-__builtin_clzll(k);i>=0;i--){
  ll an=0;
  mask+=(1LL<<i);
  if(((k>>i) & 1LL)==0)continue;
  rep(j,n){
    if((a[j]&mask)==0&&a[j]<=k)an+=b[j];
  }
  mask-=(1LL<<i);
  ans=max(ans,an);
}
ll ann=0;
rep(j,n){
  if((a[j]&mask)==0&&a[j]<=k)ann+=b[j];
}
ans=max(ans,ann);
cout << ans << endl;
return 0;
}
