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
ll a[n]={};
rep(i,n) {
    cin >> a [i];
}
ll b[n]={};
rep(i,n) {
    cin >> b [i];
}
ll aa[30]={};
ll bb[30]={};
rep(j,30)rep(i,n){
    if(a[i]>>j&1){
            aa[j]++;
        }
    if(b[i]>>j&1){
            bb[j]++;
        }
}
ll te=0;
rep(i,30){
    if(((n-aa[i])*bb[i]+aa[i]*(n-bb[i])+te)%2){
        ans+=(1<<i);
    }
    if((aa[i]*bb[i]+te)%2){
        te=1;
    }
    else te=0;
}

for (int i = 0; i <20;  ++i) {
    cout <<bb[i] << " ";
}cout  << endl;

cout << ans << endl;
return 0;
} 