#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll t[n] = {};
ll a=-10;
rep(i, n)
{
    cin >> t[i];
    t[i]--;
    if(i==t[i]&&a!=i-1)a=i;
    else if(i==t[i]&&a==i-1){ans++;a=-10;}
    else if(a==i-1){ans++;a=-10;}
}
if(a!=-10)ans++;
cout << ans << endl;
return 0;
}