#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1LL<<60;

int main()
{
ll n ;
cin >> n ;
if(n==1){
cout << 0 << endl;
return 0;
}
vector<ll> a(n),b(n);
rep(i, n){
  cin >> a[i];
  b[n-i-1]=a[i]*2;
}
b[0]=b[1];
vector<ll> v(n),vv(n);
stack<ll> s;
for (ll i = n-2; i >= 0; i--)
{
  ll r=a[i+1];
  v[i]=v[i+1];
  rep(j,20){
    if(a[i]<=r){
      rep(l,20){
        r=r>>2;
        if(a[i]<=r){s.push(2*(n-1-i));continue;}
        break;
      }
      break;
    }
    v[i]+=2*(n-1-i);
    if(s.size()>0){v[i]-=s.top();s.pop();}
    r=r<<2;
  }
}
while(!s.empty())s.pop();
for (ll i = n-2; i >= 0; i--)
{
  ll r=b[i+1];
  vv[i]=vv[i+1];
  rep(j,20){
    if(b[i]<=r){
      rep(l,20){
        r=r>>2;
        if(b[i]<=r){s.push(2*(n-1-i));continue;}
        break;
      }
      break;
    }
    vv[i]+=2*(n-1-i);
    if(s.size()>0){vv[i]-=s.top();s.pop();}
    r=r<<2;
  }
}
rep(i,n){
  ans=min(ans,v[i]+vv[n-1-i]+i);
}
cout << ans << endl;
return 0;
}