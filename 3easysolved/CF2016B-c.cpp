#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll w , h ;
cin >> w >> h ;
vector<pair<ll,ll>> v(w+h);
rep(i,w){
  cin >> v[i].first;
  v[i].second=1;
}
rep(i,h){
  cin >> v[i+w].first;
}
sort(v.begin(),v.end());
ll x=w+1,y=h+1;
rep(i,w+h){
  if(v[i].second){
    ans+=v[i].first*y;
    x--;
  }
  else{
    ans+=v[i].first*x;
    y--;
  }
}

cout << ans << endl;
return 0;
}