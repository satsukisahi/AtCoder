#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll h , w ;
cin >> h >> w ;
if(h%3==0)ans=0;
else ans=w;
if(w%3==0)ans=0;
else ans=min(ans,h);

rep(i,h+1){
  ll a=i*w;
  ll b=(h-i)*(w/2);
  ll c=(h-i)*(w-w/2);
  vector<ll> v={a,b,c};
  sort(v.begin(),v.end());
  ans=min(ans,v[2]-v[0]);
}rep(i,w+1){
  ll a=i*h;
  ll b=(w-i)*(h/2);
  ll c=(w-i)*(h-h/2);
  vector<ll> v={a,b,c};
  sort(v.begin(),v.end());
  ans=min(ans,v[2]-v[0]);
}
cout << ans << endl;
return 0;
}