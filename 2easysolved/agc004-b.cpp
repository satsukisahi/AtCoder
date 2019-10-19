#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n , x ;
cin >> n >> x ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<vector<ll>> v(n, vector<ll>(n,0) );
rep(i,n){
  ll mi;
  rep(j,n){
    mi=min(mi,a[(i-j+n)%n]);
    v[i][j]=mi;
  }
}
rep(i,n){
  ll sum=0;
  rep(j,n){
    sum+=v[j][i];
  }
  ans=min(ans,sum+i*x);
}
cout << ans << endl;

return 0;
}