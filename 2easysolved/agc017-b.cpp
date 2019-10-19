#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
ll a , b , c , d ;
cin >> a >> b >> c >> d ;
rep(i,n){
  if(i*c-(n-1-i)*d<=b-a&&b-a<=i*d-(n-1-i)*c){
    cout << "YES" << endl;
    return 0;
  }
}
cout << "NO" << endl;
return 0;
}