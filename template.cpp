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
ll n;
cin >> n; 
ll table[n]={};
rep(i,n) {
    cin >> table [i];
}


cout << ans << endl;
return 0;
} 