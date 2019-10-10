#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
const ll INF = 1LL << 62; //MAX 9223372036854775807
int main()
{
ll n , a , b , sub=0 ,sitr=-1;
cin >> n >> a >> b ;
if(a>b)swap(a,b);
vector<ll> s(n+1);
s[0]=-1LL*INF;
rep(i, n){
  cin >> s[i+1];
}
rep(i,n-2){
  if(s[i+2]-s[0]<a){
    cout << 0 << endl;
    return 0;
  }
}
vector<ll> v(n+1);
vector<ll> sum(n+1);
sum[0]=1;sum[1]=2;
v[0]=1;v[1]=1;
rep(i,n-1){
  auto itr = lower_bound(s.begin(), s.end(), s[i+1]-b);
  v[i+2]=sum[itr-s.begin()-1]-sub;
  sum[i+2]=v[i+2]+sum[i+1];
  if(v[i+2]<v[i+1]+a)while(1){
    sitr++;
    sub+=v[sitr];
    v[sitr]=0;
    if(sitr==i)break;
  }
}
for(auto an:v)ans+=an;
cout << ans << endl;
return 0;
}