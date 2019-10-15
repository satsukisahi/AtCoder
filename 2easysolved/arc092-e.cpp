#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
vector<ll>  od,ev;
ll aod=0,aev=0;
rep(i, n){
  cin >> a[i];
  if(i%2&&a[i]>=0){od.push_back(i);aod+=a[i];}
  else if(a[i]>=0){ev.push_back(i);aev+=a[i];}
}
vector<ll> b;
if(od.size()==0&&ev.size()==0){
  ll mx=-1e+10;
  ll it;
  rep(i,n)if(mx<a[i]){it=i;mx=a[i];}
  cout << mx << endl;
  b.push_back(it);
}
else if(aod>aev){
  b=od;
  cout << aod << endl;
}
else{
  b=ev;
  cout << aev << endl;
}
vector<ll> ans;
for(ll i=b.size()-1;i>0;i--){
  rep(j,(b[i]-b[i-1])/2){
    ans.push_back(2+j);
  }
}
rep(i,b.front())ans.push_back(1);
rep(i,n-b.back()-1)ans.push_back(b.back()+2+i);
cout << ans.size() << endl;
rep(i,ans.size())cout << ans[ans.size()-i-1] << endl;
return 0;
}