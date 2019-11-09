#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
string s , t ;
cin >> s >> t ;
ll a=__gcd(n,m);
rep(i,a){
  if(s[n*i/a]!=t[m*i/a]){
    cout << -1 << endl;
    return 0;
  }
}

cout << n*m/a << endl;
return 0;
}
