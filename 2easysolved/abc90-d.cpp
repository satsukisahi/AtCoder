#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{ 
ll n,k;
cin >> n>>k;
if(k==0){
    cout << n*n << endl;
return 0;
}

rep1(i,n+1){
    if(i<=k)ans+=n;
    else {
        ans+=k*(n/i)-1;
        if(n%i<k-1)ans+=n%i+1;
        else ans+=k;
    }
}
ans=n*n-ans;
cout << ans << endl;
return 0;
} 