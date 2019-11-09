#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF =(1LL<<63)-1; //MAX 9223372036854775807

ll ans = (1LL<<63)-1;

int main()
{
ll n , x ;
cin >> n >> x ;
vector<ll> t(n);
rep(i, n){
  cin >> t[i];
}
vector<ll> s;
s.push_back(0);
rep(i,n){
  s.push_back(t[i]+s[i]);
}
auto kei = [](ll y){if(y==1)return 5LL; else return y*2+1;};
rep(i,n){
  ll j=n;
  ll te=0;
  ll co=1;
  while(j>0){
    te+=kei(co)*(s[j]-s[(j-(i+1)<0) ? 0:j-(i+1)]);
    co++;
    j-=(i+1);
  }
  if(te+(i+1)*x>0)ans=min(te+(i+1)*x,ans);
}
cout << ans+n*x << endl;
return 0;
}
