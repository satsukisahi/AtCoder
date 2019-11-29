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
rep(i, n){
  cin >> a[i];
}
priority_queue<pair<ll,ll>> q;
vector<ll> b(n);
rep(i, n){
  cin >> b[i];
  q.push({b[i],i});
}
auto mod = [&](ll modx){modx%=n;modx+=n;modx%=n;return modx;};

while(q.size()!=0){
pair<ll,ll> p=q.top();
q.pop();
if(b[p.second]==a[p.second])continue;
ll te=b[mod(p.second+1)]+b[mod(p.second-1)];
ll ma=max(b[mod(p.second+1)],b[mod(p.second-1)]);
if(ma>a[p.second]){
  ans+=(b[p.second]-ma-1)/te +1;
  b[p.second]-=(b[p.second]-ma-1)/te *te;
  b[p.second]-=te;
  if(b[p.second]<a[p.second]){cout << -1 << endl;return 0;}
  q.push({b[p.second],p.second});
}
else{
  ans+=(b[p.second]-a[p.second])/te;
  b[p.second]-=(b[p.second]-a[p.second])/te *te;
  if(b[p.second]!=a[p.second]){cout << -1 << endl;return 0;}
}
}
cout << ans << endl;
return 0;
}
