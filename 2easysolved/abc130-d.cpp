#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,k;
cin >> n>>k;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}
ll tt[n+1] = {};
tt[0]=0;
repf(i, 1,n+1){
    tt[i]=t[i-1]+tt[i-1];
}
ll front=1,back=0;
while(true){
    if(tt[front]-tt[back]>=k){
        ans+=n-front+1;
        back++;
    } 
    else {
        if(front==n)break;
        front++;
    }
}



cout << ans << endl;
return 0;
}