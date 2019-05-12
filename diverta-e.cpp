#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = 0;
ll a[500001]={};

int main()
{
ll n;
cin >> n;
ll t[n] = {};
rep(i, n)
{
    cin >> t[i];
}
ll te=0;
rep(i,n){
    te=te^t[i];
    a[te]++;
}

for (int i = 0; i < 18; ++i) {
    cout << a[i] << " ";
}cout  << endl;

cout << te << endl;
return 0;
}