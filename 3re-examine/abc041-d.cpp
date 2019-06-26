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
ll g[n][n]={};
rep(i, m){
    ll a,b;
    cin >> a>>b;
    g[a-1][b-1]=1;
}
ll dp[1<<n]={};
dp[0]=1;
rep(i,1<<n){
    rep(j,n){
        if(i>>j&1){
            bool ok=1;
            rep(k,n){
                if(g[j][k]&&i>>k&1)ok=0;
            }
            if(ok)dp[i]+=dp[i^1<<j];
        }
    }
}

cout << dp[(1<<n)-1] << endl;
return 0;
}

/* 1->2->3 4 5の例
部分集合1234の場合の数
12を最後にする場合→不可
3を最後にする場合→可能で124は3通り
4を最後にする場合→可能で123は1通り
より4通り
部分集合12345の場合の数（答え）
12を最後にする場合→不可
3を最後にする場合→可能で1245は12通り
4を最後にする場合→可能で1235は4通り
5を最後にする場合→可能で1234は4通り */
