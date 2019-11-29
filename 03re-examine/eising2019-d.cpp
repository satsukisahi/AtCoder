#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , q ;
cin >> n >> q ;
vector<ll> a(n);
vector<ll> sum;
sum.push_back(0);
vector<ll> half;
half.push_back(0);
rep(i, n){
  cin >> a[i];
  sum.push_back(a[i] + sum[i]);
  half.push_back((i%2?0:a[i]) + half[i]);
}
vector<ll> x(q);
rep(i, q){
  cin >> x[i];
}
rep(i,q){
  auto judge = [&](ll val) { 
    if(val==1)return true;
    if(x[i]-a[n-2*val+1]>a[n-val]-x[i])return false;
    else return true;
  };
  auto binarysearch = [&](ll lowerbound, ll upperbound) {
    if (!judge(lowerbound)) return -1LL;
    ll lower = lowerbound, upper = upperbound;
    while (1){
      if (judge((lower + upper) / 2)) lower = (lower + upper) / 2;
      else upper = (lower + upper) / 2;
      if (abs(upper - lower) <= 1){
        if (judge(upper)) return upper;
        else return lower;
      }
    }
  };
  ll ind=binarysearch(1,(n+1)/2);
  ll ans;
  if(n%2)ans=sum[n]-sum[n-ind]+half[n-2*ind+1];
  else ans=sum[n]-sum[n-ind]+sum[n-2*ind+1]-half[n-2*ind+1];
  cout << ans << endl;
}
return 0;
}