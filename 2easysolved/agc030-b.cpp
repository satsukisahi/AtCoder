#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll l , n ;
cin >> l >> n ;
vector<ll> x(n);
vector<ll> xx(n);

rep(i, n){
  cin >> x[i];
  xx[n-i-1]=l-x[i];
}
vector<ll> s;
s.push_back(0);
rep(i,n){
  s.push_back(x[i]+s[i]);
}
vector<ll> ss;
ss.push_back(0);
rep(i,n){
  ss.push_back(xx[i]+ss[i]);
}
ll te;
rep(i,n){
  if((n-i)%2){
    te=(s[i+(n-i)/2]-s[i]+ss[(n-i)/2])*2+x[i+(n-i)/2];
    ans=max(ans,te);
    te=(ss[i+(n-i)/2]-ss[i]+s[(n-i)/2])*2+xx[i+(n-i)/2];
    ans=max(ans,te);
  }
  else{
  te=(s[i+(n-i)/2]-s[i]+ss[(n-i)/2])*2-xx[(n-i)/2-1];
  ans=max(ans,te);
  te=(ss[i+(n-i)/2]-ss[i]+s[(n-i)/2])*2-x[(n-i)/2-1];
  ans=max(ans,te);
}
}
cout << ans << endl;
return 0;
}
