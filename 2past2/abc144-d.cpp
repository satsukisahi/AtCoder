#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans = 0;

int main()
{
double a , b , x ;
cin >> a >> b >> x ;
if(a*a*b/2>x){
  ans=atan(a*b*b/(2*x));
}
else{
  ans=atan((a*b-x/a)*2/(a*a));
}
ans=ans*180/3.14159265358;
cout<<fixed<<setprecision(12)<<ans<<endl;

return 0;
}