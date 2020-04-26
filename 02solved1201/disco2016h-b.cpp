#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ,x;
cin >> n >> x;
vector<pair<ll,ll>> v(n);
rep(i,n){
  ll t ;
  cin >> t ;
  v[i].first=t;
}
rep(i,n){
  ll t ;
  cin >> t ;
  v[i].second=t;
}
sort(v.begin(),v.end());

auto judge = [&](ll val) {  
  priority_queue<ll> q;
  ll s=val,cnt=0,itr=n-1;
  while(s>0){
    while(itr>=0&&s<=v[itr].first){
      q.push(v[itr].second);
      itr--;
    }
    if(!q.empty()){cnt+=q.top();q.pop();}
    if(cnt>=x)return false;
    s--;
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
ll ans;
ans=binarysearch(0, 100010)+1;
if(ans==100011)ans=-1;
cout << ans << endl;
return 0;
}