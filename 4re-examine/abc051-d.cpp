#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m;
cin >> n>>m;
vector<vector<ll>> d(n, vector<ll>(n,INF) );
ll aa[m]={},bb[m]={},cc[m]={}; 
rep(i, m){
    ll a,b,c;
    cin >> a>>b>>c;
    a--;b--;
    d[a][b]=c;
    d[b][a]=c;
    aa[i]=a;
    bb[i]=b;
    cc[i]=c;
}
rep(i,n){
    d[i][i]=0;
}
for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

rep(i,m){
    bool ch=0;
    rep(j,n){
    if(d[aa[i]][j]+cc[i]==d[bb[i]][j])ch=1;
    }
    if(!ch)ans++;
}

cout << ans << endl;
ans;
return 0;
}
