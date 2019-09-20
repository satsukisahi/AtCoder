#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
ll su=0;
rep(i, n){
  cin >> a[i];
  su^=a[i];
}
rep(i,60){
  if(su>>i & 1LL){
    ans+=1LL<<i;
  }
}
rep(i,n){
  a[i]=(a[i]|ans)^ans;
}
ll syu=0;
for (ll i = 59; i >= 0; i--)
{
  for(ll j = syu; j < n; j++){
  if(a[j]>>i & 1LL){
    rep(k,n){
      if(j==k)continue;
      if(a[k]>>i & 1LL)a[k]^=a[j];
    }
    swap(a[syu],a[j]);
    syu++;
    break;
  }
  }
}
ll te=0;
rep(i,syu){
  te^=a[i];
}
ans+=te*2;
cout << ans << endl;
return 0;
}