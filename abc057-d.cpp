#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
double ans = 0;
ll dp[30000][101];
//二項係数mod
const ll MAX = 510000;
const ll MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

    // テーブルを作る前処理
    void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (ll i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    // 二項係数計算
    long long COM(ll n, ll k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
int main()
{
ll n,a,b;
cin >> n>>a>>b;
ll v[n] = {};
rep(i, n)
{
    cin >> v[i];
}
sort(v, v+n);
rep(i,a){
    ans+=v[n-1-i];
}
ans/=a;
ll con=0;
ll p,k;

while(true){
    ll re=v[n-1-con];
    auto itr1 = lower_bound(v,v+n, re);
    auto itr2 = upper_bound(v,v+n, re);
    if(con+itr2 - itr1>=b){
        p=b-con;
        k=itr2 - itr1;
        break;
    }
    con+=itr2 - itr1;
}
ll ans2=0;
COMinit();

rep1(i,p+1){
    ans2+=COM(k, i);
    //cout << COM(k, i) << endl;
}

cout<<fixed<<setprecision(10)<<ans<<endl;
cout << ans2 << endl;
return 0;
}