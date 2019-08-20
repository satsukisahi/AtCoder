#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;
const ll mo = 998244353;


int main()
{
ll n;
string  s ;
cin >> n >> s ;
ll r=0,g=0,b=0;

rep(i,3*n){
  if(s[i]=='B'){
    if(r>0&&g>0){ans*=min(r,g);ans%=mo;r--;g--;}
    else if(r>0){if(r-b>0)ans*=r-b;ans%=mo;b++;}
    else if(g>0){if(g-b>0)ans*=g-b;ans%=mo;b++;}
    else b++;
  }
  if(s[i]=='R'){
    if(b>0&&g>0){ans*=min(b,g);ans%=mo;b--;g--;}
    else if(b>0){if(b-r>0)ans*=b-r;ans%=mo;r++;}
    else if(g>0){if(g-r>0)ans*=g-r;ans%=mo;r++;}
    else r++;
  }
  if(s[i]=='G'){
    if(r>0&&b>0){ans*=min(r,b);ans%=mo;r--;b--;}
    else if(r>0){if(r-g>0)ans*=r-g;ans%=mo;g++;}
    else if(b>0){if(b-g>0)ans*=b-g;ans%=mo;g++;}
    else g++;
  }
}
rep(i,n){
  ans*=i+1;
  ans%=mo;
}
cout << ans << endl;
return 0;
}
