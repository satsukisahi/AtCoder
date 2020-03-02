#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , d , a ;
cin >> n >> d >> a ;
vector<pair<ll,ll>> v(n);
rep(i,n){
  cin >> v[i].first >> v[i].second;
  v[i].second=(v[i].second+a-1)/a;
}
sort(v.begin(),v.end());
ll at=0;
queue<pair<ll, ll>> q;
rep(i,n){
  while(!q.empty()){
    auto r=q.front();
    if(r.first<v[i].first){
      q.pop();
      at-=r.second;
    }
    else break;
  }
  if(v[i].second>at){
    ans+=v[i].second-at;
    q.push({v[i].first+2*d,v[i].second-at});
    at+=v[i].second-at;
  }
}
cout << ans << endl;
return 0;
}