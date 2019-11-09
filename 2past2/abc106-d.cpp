#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807

int main()
{
ll n,m,q;
cin >> n >> m >> q ;
ll ans[q] = {};
ll t[n][n] = {};
rep(i, m){
    ll ss,tt;
    cin >> ss >> tt ;
    ss--;tt--;
    t[ss][tt]++;
}
vector<vector<ll>> s(n+1, vector<ll>(n+1,0) );
rep(i,n)rep(j,n){
    s[i+1][j+1]=t[i][j]+s[i][j+1]+s[i+1][j]-s[i][j];
}

rep(i,q){
    ll pp,qq;
    cin >> pp >> qq ;
    pp--;qq--;
    ans[i]=s[qq+1][qq+1]-s[qq+1][pp]-s[pp][qq+1]+s[pp][pp];
}

rep(i,q)cout << ans[i] << endl;
return 0;
}
