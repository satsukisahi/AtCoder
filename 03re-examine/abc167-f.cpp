#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v,vv;
ll cnt=0;
rep(i,n){
  string s ;
  cin >> s ;
  ll te=0,tt=0;
  rep(j,s.size()){
    if(s[j]==')'&&te==0){tt++;cnt--;}
    else if(s[j]==')'){te--;cnt--;}
    else {te++;cnt++;}
  }
  if(te>=tt)v.emplace_back(tt,te);
  else vv.emplace_back(te,tt);
}
if(cnt!=0){cout << "No" << endl;return 0;}
sort(v.begin(),v.end());
sort(vv.begin(),vv.end());
reverse(vv.begin(),vv.end());
ll nw=0;
for(auto r:v){
  nw-=r.first;
  if(nw<0){cout << "No" << endl;return 0;}
  nw+=r.second;
}
for(auto r:vv){
  nw-=r.second;
  if(nw<0){cout << "No" << endl;return 0;}
  nw+=r.first;
}
cout << "Yes" << endl;
return 0;
}
