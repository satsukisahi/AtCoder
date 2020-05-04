#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
if(n%2){
  rep(i,m){
cout << i+1 <<' '<<n-i<< endl;
  }
}
else{
  ll cnt=1;
  ll b=n/2-1;
  for (ll i = 1; i <= (b+1)/2; i++)
  {
    if(cnt>m)break;
    cout << i <<' '<<b-(i-1)+1<< endl;
    cnt++;
  }
  for (ll i = 1; i <= (b+1)/2; i++)
  {
    if(cnt>m)break;
    cout << i+b+1 <<' '<<b-(i-1)+1+b<< endl;
    cnt++;
  }
}
return 0;
}