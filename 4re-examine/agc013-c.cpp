#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , l , t ;
cin >> n >> l >> t ;
auto mod = [&](ll modx){modx%=l;modx+=l;modx%=l;return modx;};
auto mod2 = [&](ll modx){modx%=n;modx+=n;modx%=n;return modx;};

vector<ll> v;
vector<ll> ans;
ll cnt=0;
rep(i,n){
  ll x , w ;
  cin >> x >> w ;
  if(w==1){
    ans.push_back(mod(x+t));
    cnt+=(x+t)/l;
  }
  else {
    ans.push_back(mod(x-t));
    cnt-=(t-x+l-1)/l;
  }
}
sort(ans.begin(),ans.end());
rep(i,n){
  cout << ans[mod2(i+cnt)] << endl;
}
return 0;
}