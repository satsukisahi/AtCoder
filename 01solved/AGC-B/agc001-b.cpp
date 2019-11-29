#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , x ;
cin >> n >> x ;
ll a=x,b=n-x;
ans+=n;
while(1){
  if(b>a){
    ans+=b/a*2*a;
    b=b%a;
  }
  else{
    ans+=a/b*2*b;
    a=a%b;
  }
  if(a*b==0){
    ans-=max(a,b);
    break;
  }
}
cout << ans << endl;
return 0;
}
