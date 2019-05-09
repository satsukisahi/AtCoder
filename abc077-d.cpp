#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = INF;
ll sum(ll n){
    ll sum=0;
    ll i=1;
    while(n/i!=0){
        i*=10;
        sum+=(n-(n/i)*i)*10/i;
        n-=(n-(n/i)*i);
    }
    return sum;
}

int main()
{
ll n;
cin >> n;
rep1(i,11){
    ans=min(ans,sum(i*n));
}

cout << ans << endl;
return 0;
}