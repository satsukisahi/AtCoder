#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
string s ;
cin >> s ;
vector<ll> v;
rep(i,n){
  v.push_back(s[i]-'1');
}
bool ok=1;
rep(i,n)if(v[i]==1)ok=0;
if(ok)rep(i,n)v[i]/=2;
ll sum=0;
rep(i,n-1){
  sum+=__builtin_ffsll(n-1-i)-__builtin_ffsll(i+1);
  if(sum==0)ans=(ans+v[i+1])%2;
}
ans=(ans+v[0])%2;
if(ok)ans*=2;
cout << ans << endl;
return 0;
}