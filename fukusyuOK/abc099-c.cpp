#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
vector<ll> dp(100100, 999); 

int main()
{
ll n;
cin >> n;
dp[0]=0;
ll dp9[6]={9,81,729,6561,59049,531441};
ll dp6[]={6,36,216,1296,7776,46656,279936};
for(ll i = 0; i < 100001; i++){
    rep(j,6){
        if(i+dp9[j]<100001){
            dp[i+dp9[j]]=min(dp[i+dp9[j]],dp[i]+1);
        }
    }
    rep(j,7){
        if(i+dp6[j]<100001){
            dp[i+dp6[j]]=min(dp[i+dp6[j]],dp[i]+1);
        }
    }
    dp[i+1]=min(dp[i+1],dp[i]+1);
}
cout << dp[n] << endl;
return 0;
}
