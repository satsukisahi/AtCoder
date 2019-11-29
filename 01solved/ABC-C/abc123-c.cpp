#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
ll a[5];
rep(i,5){
cin >> a[i];
}
sort(a, a + 5);

ans=n/a[0]+5;
if(n%a[0]==0){
    ans--;
}

cout << ans << endl;
return 0;
}



