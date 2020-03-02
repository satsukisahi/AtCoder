#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , a , b ;
cin >> n >> a >> b ;
if((b-a)%2){
  ans=min(a+(b-a-1)/2,n-b+1+(b-a-1)/2);
}
else ans=(b-a)/2;
cout << ans << endl;
return 0;
}