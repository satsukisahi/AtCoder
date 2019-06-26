#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
struct name
{
    ll x,y,cost;
};

bool cmp(const name &a, const name &b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int main()
{
ll n;
cin >> n;
name t[n] = {};
rep(i, n){
    cin >> t[i].x>>t[i].y;
}
sort(t,t+n,cmp);

rep(i, n){
    cout << t[i].x<<t[i].y << endl;
}
return 0;
}
