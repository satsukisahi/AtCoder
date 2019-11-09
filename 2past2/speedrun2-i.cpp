#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;

int main()
{
ll n ;
cin >> n ;
vector<ll> va,vb;
ll a , b ;
cin >> a >> b ;
va.push_back(a);
vb.push_back(b);

rep(i,n-1){
  ll aa , bb ;
  cin >> aa >> bb ;
  va.push_back(aa);
  vb.push_back(bb);
  if((aa+b-1)/b>(a+bb-1)/bb){
    a=aa;b=bb;ans=i+2;
  }
}
if(ans!=-1)rep(i,n){
  if(ans==i+1)continue;
  if((va[i]+b-1)/b>=(a+vb[i]-1)/vb[i]){
    ans=-1;
    break;
  }
}
cout << ans << endl;
return 0;
}