#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
sort(a.begin(),a.end());

//lower側がtrue judgeがtrueとなる最もupper側のvalを返す
//lowerboundでもfalseなら-1を返す
auto judge = [&](ll val) { 
  ll cnt=0;
  rep(i,n){
    if(a[i]==0){
      if(val>=0)cnt+=n-i-1;
    }
    if(a[i]>0&&val>0){
      ll p=upper_bound(a.begin(), a.end(), val/a[i])-a.begin();
      cnt+=max(0LL,p-i-1);
    }
    if(a[i]<0){
      if(val<=0)cnt+=a.end()-lower_bound(a.begin(), a.end(), (a[i]+1+val)/a[i]);
      else {
        ll p=a.end()-lower_bound(a.begin(), a.end(), val/a[i]);
        cnt+=min(p,n-i-1);
      }
    }
    if(cnt>=k)return false;
  }
  return true; 
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
cout << binarysearch(-INF, INF)+1 << endl; 

return 0;
}