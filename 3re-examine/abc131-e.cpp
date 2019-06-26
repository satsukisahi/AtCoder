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
if((n-1)*(n-2)/2<k){
    cout << -1<< endl;
    return 0;
}
ll cou=(n-1)*(n-2)/2-k;
cout << cou+n-1 << endl;
rep(i,n-1){
    cout << 1<<" "<<i+2 << endl;
}

rep(i,n-2)repf(j,i+1,n-1){
    if(cou==0)return 0;
    cout << i+2<<" "<<j+2 << endl;
    cou--;
}

return 0;
}