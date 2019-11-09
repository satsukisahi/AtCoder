#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll n;
cin >> n;
pair<ll, ll> t[n];
rep(i, n){
    cin >> t[i].second>> t[i].first;
}
ll tim=0,now=0;
sort(t,t+n);
rep(i,n){
    tim=t[i].first;
    now+=t[i].second;
    if(tim<now){
        cout << "No" << endl;
        return 0;
    }
}

cout << "Yes" << endl;
return 0;
}