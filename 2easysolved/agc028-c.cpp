#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v;
ll asum=0,bsum=0;
rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  asum+=a;
  bsum+=b;
  v.push_back({a,i});
  v.push_back({b,i});
}
sort(v.begin(),v.end());
set<ll> s;
rep(i,n){
  ans+=v[i].first;
  s.insert(v[i].second);
}
ll anss=INF;
if(s.size()==n){
  if(v[n].second==v[n-1].second){
    anss=ans;
    ans-=v[n-2].first;
    anss+=v[n+1].first;
    anss-=v[n-1].first;
  }
  else ans-=v[n-1].first;
  ans+=v[n].first;
}
ans=min({ans,asum,bsum,anss});
cout << ans << endl;
return 0;
}
