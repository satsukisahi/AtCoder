#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
  std::ifstream in("input");
  std::cin.rdbuf(in.rdbuf());
ll n , k , mx=0;
cin >> n >> k ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> f(n);
rep(i, n){
  cin >> f[i];
}
sort(a.begin(),a.end()); 
sort(f.rbegin(),f.rend());
rep(i,n)mx=max(a[i]*f[i],mx);

auto judge = [&](ll val) {
  ll num=0;
  rep(i,n){
    if(a[i]*f[i]>val)num+=a[i]-val/f[i];
  }
  if(num>k)return false;
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

cout << binarysearch(mx,0) << endl;
return 0;
}