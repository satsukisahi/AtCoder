#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> a(n);
rep(i, n){
  cin >> a[i].first;
  a[i].second=i+1;
}
sort(a.begin(),a.end());
reverse(a.begin(),a.end());

vector<vector<ll>> v(n+1, vector<ll>(n,0) );
rep(i,n){
  rep(j,n-1){
    if(i<j)continue;
    v[i+1][j]=max(v[i+1][j],v[i][j]+a[i].first*abs(n-i+j-a[i].second));
    v[i+1][j+1]=max(v[i+1][j+1],v[i][j]+a[i].first*abs(j+1-a[i].second));
  }
}
rep(i,n){
  ans=max(ans,v[n][i]);
}
cout << ans << endl;
return 0;
}