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
if(n%2==0){
ll sum=0;
rep(i,n){
  if(i%2)sum+=a[i];
}
ans=sum;
rep(i,n/2){
  sum+=a[i*2]-a[i*2+1];
  ans=max(ans,sum);
}
}
else{
vector<vector<ll>> v(n+1, vector<ll>(3,0) );
rep(i,n){
  if(i%2){
    v[i+1][0]=v[i][0];
    v[i+1][1]=max(v[i][0],v[i][1]+a[i]);
    v[i+1][2]=v[i][2];
  }
  else{
    v[i+1][0]=v[i][0]+a[i];
    v[i+1][1]=v[i][1];
    v[i+1][2]=max(v[i][1],v[i][2]+a[i]);
  }
}
ans=max({v[n][0],v[n][1],v[n][2]});
}
cout << ans << endl;
return 0;
}