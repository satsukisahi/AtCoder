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
ll n,c;
cin >> n>>c; 
P pa[n];
rep(i,n){
    cin >> pa[i].first>>pa[i].second; 
}
ll r[n];
ll l[n];
ll r2[n];
ll l2[n];
rep(i,n){
    if(i==0)r[i]=pa[i].second-pa[i].first;
    else r[i]=r[i-1]+pa[i].second-pa[i].first+pa[i-1].first;
    r2[i]=r[i]-pa[i].first;
    if(i==0)l[i]=pa[n-1-i].second-c+pa[n-1-i].first;
    else l[i]=l[i-1]+pa[n-1-i].second-pa[n-i].first+pa[n-1-i].first;
    l2[i]=l[i]-c+pa[n-1-i].first;
}
ll ma;
rep(i,n){
    if(i==0)ma=r[i];
    else if(ma>r[i])r[i]=ma;
    else ma=r[i];
}
ans=ma;
rep(i,n){
    if(i==0)ma=l[i];
    else if(ma>l[i])l[i]=ma;
    else ma=l[i];
}
ans=max(ans,ma);
rep(i,n-1){
    ans=max(r2[i]+l[n-i-2],ans);
    ans=max(l2[i]+r[n-i-2],ans);
}

/* for (int i = 0; i < n; ++i) {
    cout << l[i] << " ";
}cout  << endl; */
if(ans<0)ans=0;
cout << ans << endl;
return 0;
} 