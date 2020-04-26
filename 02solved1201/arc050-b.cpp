#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll r , b ;
cin >> r >> b ;
ll x , y ;
cin >> x >> y ;
auto judge = [&](ll val) { 
  if(r-val<0||b-val<0)return false;
  return val <= (r-val)/(x-1)+(b-val)/(y-1) ;
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
cout << binarysearch(0, 1LL<<60) << endl;
return 0;
}