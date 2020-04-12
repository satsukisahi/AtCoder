#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
rep(i,n){
  if((i+1)%3!=0&&(i+1)%5!=0)ans+=i+1;
}
cout << ans << endl;
return 0;
}