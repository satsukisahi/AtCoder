#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans,cnt;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
sort(a.rbegin(),a.rend());
vector<ll> csum;
csum.push_back(0);
rep(i, n)
{
  csum.push_back(a[i] + csum[i]);
}
auto judge = [&](ll val) {
  ll ind=n-1;
  cnt=0;ans=0;
  rep(i,n){
    while(ind>=0&&a[i]+a[ind]<val){
      ind--;
    }
    cnt+=ind+1;
    ans+=a[i]*(ind+1)+csum[ind+1];
    if(cnt>=m)return 0;
  }
  return 1;
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
ll s=binarysearch(INF,0);
judge(s);
ans+=(m-cnt)*(s-1);
cout << ans << endl;
return 0;
}