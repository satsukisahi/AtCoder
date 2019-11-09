#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
sort(a.begin(),a.end());
vector<ll> sum;
sum.push_back(0);
rep(i, n)
{
  sum.push_back(a[i] + sum[i]);
}
rep(i,n-1){
  if(sum[n-i-1]*2>=a[n-i-1])ans++;
  else break;
}
cout << ans+1 << endl;
return 0;
}