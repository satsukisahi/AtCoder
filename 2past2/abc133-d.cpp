#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n;
cin >> n;
ll t[n] = {};
ll ans[n] = {};
rep(i, n){
    cin >> t[i];
    t[i]=t[i]*2;
}
ll k=0;
rep(i,n-1){
    k=t[i]-k;
}
ans[0]=(t[n-1]-k)/2;
rep(i,n-1){
    ans[i+1]=t[i]-ans[i];
}
for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
}cout  << endl;

return 0;
}
