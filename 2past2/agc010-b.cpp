#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
ll sum=0;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
  sum+=a[i];
}

if(sum%((1+n)*n/2)!=0){cout << "NO" << endl;return 0;}
sum/=(1+n)*n/2;
rep(i,n-1){
  if((a[i]+sum-a[i+1])%n!=0){cout << "NO" << endl;return 0;}
  if(a[i+1]-a[i]>sum){cout << "NO" << endl;return 0;}
}
if((a[n-1]+sum-a[0])%n!=0){cout << "NO" << endl;return 0;}
if(a[n-1]-a[0]>sum){cout << "NO" << endl;return 0;}
cout << "YES" << endl;
return 0;
}
