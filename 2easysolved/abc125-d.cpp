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
ll t[n]={};
rep(i,n) {
    cin >> t [i];
}
ll count=0;
ll min=1100000000;
rep(i,n) {
    if(t[i]<0)count++;
}
if(count%2){
    rep(i,n){
        ans+=abs(t[i]);
        if(min>abs(t[i]))min=abs(t[i]);
    }
    ans=ans-2*min;
}
else{
    rep(i,n){
        ans+=abs(t[i]);
    }
}

cout << ans << endl;
return 0;
} 