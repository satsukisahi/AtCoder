#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll a[6]={0,0,(ll)1e+9,1,(ll)1e+9-(n-1)%(ll)1e+9 -1,(n-1)/(ll)1e+9 +1};

rep(i,5){
    cout <<a[i] << " ";
}
    cout <<a[5] << endl;

return 0;
}
