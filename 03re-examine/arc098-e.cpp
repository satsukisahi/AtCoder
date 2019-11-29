#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n , k , q ;
cin >> n >> k >> q ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
rep(i,n){
  ll mi=a[i];
  vector<ll> v;
  vector<ll> te;
  rep(j,n+1){
    if(j==n||a[j]<mi){
      if(te.size()>=k){
        sort(te.begin(),te.end());
        rep(l,te.size()-k+1)v.push_back(te[l]);
      }
      te.clear();
    }
    else{
      te.push_back(a[j]);
    }
  }
  sort(v.begin(),v.end());
  if(v.size()>=q)ans=min(ans,v[q-1]-v[0]);
}
cout << ans << endl;
return 0;
}
