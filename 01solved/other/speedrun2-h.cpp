#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  if(a==b)cout << -1 << endl;
  else cout << abs(a-b) << endl;
}
return 0;
}