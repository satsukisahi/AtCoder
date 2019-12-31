#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> a(n*6);
vector<double> ans(n*6);
vector<vector<ll>> v(n);

rep(i, n*6){
  cin >> a[i].first;
  a[i].second=i/6;
}
sort(a.rbegin(),a.rend());
rep(i,n*6){
  v[a[i].second].push_back(i);
}
ll mx=0;
rep(i,n*6){
  double t=ans[mx]+1;
  rep(j,6){
      if(v[a[i].second][j]>=i)ans[v[a[i].second][j]]+=t/6;
      if(ans[v[a[i].second][j]]>ans[mx])mx=v[a[i].second][j];
  }
}
cout<<fixed<<setprecision(12)<<ans[mx]+1<<endl;
return 0;
}