#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> aa(n);
ll c=0;
rep(i, n){
  cin >> aa[i];
  if(i>1)c^=aa[i];
}
ll sum=aa[0]+aa[1]-c;
ll a=0,b=c;
if(sum<0){
  cout << -1 << endl;
  return 0;
}
rep(i,62){
  ll j=61-i;
  if(((a>>j)&1LL)==0 && ((b>>j)&1LL)==0 && sum>=2LL<<j){
    a+=1LL<<j;
    b+=1LL<<j;
    sum-=2LL<<j;
  }
}
if(sum!=0){
  cout << -1 << endl;
  return 0;
}
if(a>aa[0]){
  cout << -1 << endl;
  return 0;
}
rep(i,62){
  ll j=61-i;
  if((((a>>j)&1LL)^ ((b>>j)&1LL))==1 && aa[0]>=a+(1LL<<j)){
    a+=1LL<<j;
    b-=1LL<<j;
  }
}
if(a==0){
  cout << -1 << endl;
  return 0;
}
cout << aa[0]-a << endl;
return 0;
}