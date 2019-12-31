#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<pair<ll,ll>> v;
vector<pair<ll,ll>> vv;
rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  v.emplace_back(a,b);
}
rep(i,m){
  ll a , b ;
  cin >> a >> b ;
  vv.emplace_back(a,b);
}
rep(i,m+1){
auto judge_d = [&](double val) {
  vector<double> a;
  rep(j,n)a.push_back(v[j].second-v[j].first*val);
  if(i!=m)a.push_back(vv[i].second-vv[i].first*val);
  sort(a.begin(),a.end());
  double s=0;
  rep(i,5)s+=a[a.size()-1-i];
  return s>=0; 
  };
auto binarysearch_d = [&](double lowerbound, double upperbound) {
  if (!judge_d(lowerbound)) return -1.0;
  double lower = lowerbound, upper = upperbound;
  while (1){
    if (judge_d((lower + upper) / 2)) lower = (lower + upper) / 2;
    else upper = (lower + upper) / 2;
    if (fabs(upper - lower) <= 0.00000001){
      return upper;
    }
  }
};
ans=max(ans,binarysearch_d(0, 100000));
}
cout<<fixed<<setprecision(12)<<ans<<endl;
return 0;
}