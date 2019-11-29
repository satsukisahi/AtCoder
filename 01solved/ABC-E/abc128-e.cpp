#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


int main()
{
ll n , q ;
cin >> n >> q ;
vector<pair<ll,ll>> v;
rep(i,n){
  ll s , t , x ;
  cin >> s >> t >> x ;
  s-=x;if(s<0)s=0;
  t-=x;if(t<0)t=0;
  if(t>0){
  v.push_back({s,x});
  v.push_back({t,-x});
  }
}
sort(v.begin(),v.end());
vector<ll> ans(q);
multiset<ll> s;
ll itr=0;
rep(i,q){
  ll d ;
  cin >> d ;
  while(itr<v.size() && d>=v[itr].first){
    if(v[itr].second>0)s.insert(v[itr].second);
    else s.erase(s.find(-1*v[itr].second));
    itr++;
  }
  if(s.size()>0)ans[i]=*s.begin();
  else ans[i]=-1;
}

for(auto an:ans)cout << an << endl;
return 0;
}