#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = 0;

int main()
{
ll n,z,w;
cin >> n>>z>>w;
ll t[n] = {};
rep(i, n)
{
    cin >> t[i];
}
if(n==1){
    cout << abs(w-t[n-1]) << endl;
    return 0;
}


cout << max(abs(w-t[n-1]),abs(t[n-1]-t[n-2])) << endl;
return 0;
}