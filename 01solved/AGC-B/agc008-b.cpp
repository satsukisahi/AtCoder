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
rep(i, n){
  cin >> a[i];
}
vector<ll> s;
s.push_back(0);
rep(i,n){
  s.push_back(a[i]+s[i]);
}
vector<ll> ss;
ss.push_back(0);
rep(i,n){
  if(a[i]>0)ss.push_back(a[i]+ss[i]);
  else ss.push_back(0+ss[i]);
}
rep(i,n-k+1){
  ans=max(ans,(s[k+i]-s[i]>0 ? s[k+i]-s[i]:0)+ss[i]+ss[n]-ss[k+i]);
}
cout << ans << endl;
return 0;
}