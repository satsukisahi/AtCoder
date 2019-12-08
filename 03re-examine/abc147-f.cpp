#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans=0;
const ll INF = 1LL << 60;
int main()
{
ll n , x , d ;
cin >> n >> x >> d ;
if(d==0){
cout << ((x==0)?1:n+1) << endl;
return 0;
}
if(d<0){d*=-1;x*=-1;}
map<ll,vector<pair<ll,ll>>> m;
auto mod = [&](ll modx) {modx%=d;modx+=d;modx%=d;return modx; };
rep(i,n+1){
  m[mod(i*x)].emplace_back((i*(i-1)/2)*d+i*x,((n-1+n-i)*i/2)*d+i*x);
}
for(auto r:m){
  ll p=-INF;
  sort(r.second.begin(),r.second.end());
  for(auto rr:r.second){
    ans+=max(0LL,(rr.second+d-max(p,rr.first)))/d;
    p=max(p,rr.second+d);
  }
}
cout << ans << endl;
return 0;
}
