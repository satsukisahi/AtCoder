#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans[50][50][2501] = {};



int main()
{
ll n;
cin >> n;
ll t[n][n] = {};
rep(i, n)rep(j, n){
    cin >> t[i][j];
}
vector<vector<ll>> s(n+1, vector<ll>(n+1,0) );
rep(i,n)rep(j,n){
    s[i+1][j+1]=t[i][j]+s[i][j+1]+s[i+1][j]-s[i][j];
}
rep(i,n)rep(j,n){
    for (ll k = i; k < n; k++)for (ll l = j; l < n; l++)
    {
        ans[i][j][(k-i+1)*(l-j+1)]=max(ans[i][j][(k-i+1)*(l-j+1)],s[l+1][k+1]-s[l+1][i]-s[j][k+1]+s[j][i]);
    }
}
rep(i,n)rep(j,n)rep(k,n*n+1){
    ans[i][j][k+1]=max(ans[i][j][k],ans[i][j][k+1]);
}

ll q;
cin >> q;
ll an[q]={};
rep(i, q){
    ll qq;
    cin >> qq;
    rep(j,n)rep(k,n)an[i]=max(an[i],ans[j][k][qq]);
}
rep(i,q)
cout << an[i] << endl;
return 0;
}
