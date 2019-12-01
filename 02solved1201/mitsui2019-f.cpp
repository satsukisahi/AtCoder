#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll t1 , t2 ;
cin >> t1 >> t2 ;
ll a1 , a2 ;
cin >> a1 >> a2 ;
ll b1 , b2 ;
cin >> b1 >> b2 ;
if(a1<b1){
  swap(a1,b1);
  swap(a2,b2);
}
if(a1*t1+a2*t2>b1*t1+b2*t2){
  cout << 0 << endl;
  return 0;
}
if(a1*t1+a2*t2==b1*t1+b2*t2){
  cout << "infinity" << endl;
  return 0;
}
ll cal=a1*t1-b1*t1;
ll cal2=b1*t1+b2*t2-a1*t1-a2*t2;
ll k=cal/cal2;
ans=1+k*2;
if(cal%cal2==0)ans--;
cout << ans << endl;
return 0;
}