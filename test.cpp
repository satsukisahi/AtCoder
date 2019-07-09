#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}
deque<ll> q;
rep(i,n){
    q.push_back(t[i]);
}
rep(i,n){
    ll p=q.back();
    q.pop_back();
    cout << p << endl;

}
return 0;
}
