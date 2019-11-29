#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n,m;
cin >> n >> m ;

vector<vector<ll>> d(n, vector<ll>(n,INF) ); //d[u][v]はuからvへコスト　存在しないとINF、d[i][i]=0
rep(i,n){d[i][i]=0;}

rep(i, m){
    ll a,b,t;
    cin >> a>>b>>t;
    d[a-1][b-1]=t;
    d[b-1][a-1]=t;
}

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

rep(i,n){
    ll maxx=0;
    rep(j,n){
        maxx=max(d[i][j],maxx);
    }
    ans=min(ans,maxx);
}

cout << ans << endl;
return 0;
}
