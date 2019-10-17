#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<vector<ll>> v(m+1);
ll ad=0,hv=0;
rep(i,n-1){
  v[a[i]].push_back(1);
  v[a[i+1]].push_back(a[i+1]>a[i] ? -a[i+1]+a[i]:-m+a[i]-a[i+1]);
  if(a[i+1]<a[i]){
    ad+=m-a[i]+1;
    hv++;
  }
  ans+=a[i+1]>a[i] ? a[i+1]-a[i]:m-a[i]+a[i+1];
}
ll an=ans;
rep(i,m){
  ans=min(ans,an-ad+hv);
  for(auto r:v[i+1]){
    if(r==1)hv++;
    else {
      hv--;
      ad+=r;
    }
  }
  ad+=hv;
}
cout << ans << endl;
return 0;
}