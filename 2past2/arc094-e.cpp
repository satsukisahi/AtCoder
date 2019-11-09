#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 10000000000;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
vector<ll> b(n);
ll sum=0;
rep(i, n){
  cin >> a[i] >> b[i];
  sum+=a[i];
}
rep(i,n){
  if(a[i]>b[i])ans=min(ans,b[i]);
}
if(ans==10000000000)ans=sum;
cout << sum-ans << endl;
return 0;
}