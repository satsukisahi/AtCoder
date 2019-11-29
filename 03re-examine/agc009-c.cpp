#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
const ll INF = 1LL << 62; //MAX 9223372036854775807
int main()
{
ll n , a , b ;
cin >> n >> a >> b ;
if(a>b)swap(a,b);
vector<ll> s(n+1);
s[0]=-1LL*INF;
rep(i, n){
  cin >> s[i+1];
}
rep(i,n-1){
  if(s[i+2]-s[i]<a){
    cout << 0 << endl;
    return 0;
  }
}
vector<ll> v(n+1);
ll sum=1,st=0,en=1;
v[0]=1;v[1]=1;
for(ll i=2;i<=n;i++){
  while(s[en]<=s[i]-b){
    sum+=v[en];
    sum%=mo;
    en++;
  }
  v[i]=sum;
  if(s[i-1]>s[i]-a){
    while(1){
      if(st!=en){
        sum-=v[st];
        sum%=mo;
      }
      v[st]=0;
      st++;
      if(st>en)en++;
      if(st==i-1)break;
    }
  }
}
for(auto an:v)ans=(ans+an+mo)%mo;;
cout << ans << endl;
return 0;
}