#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
string ans = "";

int main()
{
ll n , k ;
cin >> n >> k ;
string s ;
cin >> s ;
map<char,ll> m;
rep(i,n){
  m[s[i]]++;
}
rep(i,n){
  rep(j,26){
    char r=('a'+j);
    string ss=ans+r;
    ll cnt=0;
    auto mm=m;
    rep(l,i+1){
      if(s[l]!=ss[l])cnt++;
      mm[ss[l]]--;
    }
    if(mm[ss[i]]==-1)continue;
    rep(l,n-i-1){
      if(mm[s[i+l+1]]>0)mm[s[i+l+1]]--;
      else cnt++;
    }
    if(cnt<=k){ans+=r;break;}
  }
}
cout << ans << endl;
return 0;
}