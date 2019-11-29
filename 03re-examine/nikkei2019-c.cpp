#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v;
rep(i,n){
  ll a ;
  cin >> a ;
  v.emplace_back(0,a);
}
rep(i,n){
  ll b ;
  cin >> b ;
  v[i].first=b;
}
sort(v.begin(),v.end());
vector<pair<ll,ll>> vv;
rep(i,n){
  vv.emplace_back(v[i].second,i);
}
sort(vv.begin(),vv.end());
rep(i,n){
  if(vv[i].first>v[i].first){
    cout << "No" << endl;
    return 0;
  }
}
vector<bool> see(n);
see[0]=1;
ll num=1,to=vv[0].second;
while(1){
  if(see[to]==1)break;
  see[to]=1;
  to=vv[to].second;
  num++;
}
if(num!=n){
  cout << "Yes" << endl;
  return 0;
}
rep(i,n-1){
  if(v[i].first>=vv[i+1].first){
    cout << "Yes" << endl;
    return 0;
  }
}

cout << "No" << endl;
return 0;
}