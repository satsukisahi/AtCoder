#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> ans(n);
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
map<ll,pair<ll,ll>> m;
rep(i,n){
  m[a[i]].first++;
  if(m[a[i]].first==1)m[a[i]].second=i+1;
}
ll num=0,cnt,itr;
ll minitr;
ll sum=0;
for (auto i = m.rbegin(); i != m.rend(); ++i) {
  if(num==0){
    num=i->first;
    cnt=i->second.first;
    itr=i->second.second;
    minitr=itr-1;
    continue;
  }
  ans[minitr]+=(cnt+sum)*(num-i->first);
  sum+=cnt;
  num=i->first;
  cnt=i->second.first;
  itr=i->second.second;
  minitr=min(minitr,itr-1);
}
ans[minitr]+=(cnt+sum)*num;
for(auto an:ans)cout << an << endl;
return 0;
}