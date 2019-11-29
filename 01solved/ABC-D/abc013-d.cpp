#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807

int main()
{
ll n,m,d;
cin >> n >>m >>d;
ll a[m] = {};
rep(i, m){
    cin >> a[i];
}
ll ami[n];
rep(i,n){
    ami[i]=i;
}
rep(i,m){
    swap(ami[a[i]-1],ami[a[i]]);
}
ll dub[64-__builtin_clzll(d)][n];
rep(i,n){
    dub[0][ami[i]]=i;
}
rep(j,64-__builtin_clzll(d)-1)rep(i,n){
    dub[j+1][i]=dub[j][dub[j][i]];
}

ll ans[n];
rep(i,n){
    ans[i]=i;
}
rep(i,64-__builtin_clzll(d)){
    if(d>>i & 1LL){
        vector<ll> v(n);
        rep(j,n){
            v[j]=dub[i][ans[j]];
        }
        rep(j,n){
            ans[j]=v[j];
        }
    }
}


rep(i,n){
cout << ans[i]+1 << endl;
}
return 0;
}
