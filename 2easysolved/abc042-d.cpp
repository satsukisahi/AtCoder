#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
//二項係数mod
    const int MAX = 510000;
    const int MOD = 1000000007;
    long long fac[MAX], finv[MAX], inv[MAX];

    // テーブルを作る前処理
    void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    // 二項係数計算
    long long COM(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }


int main()
{
ll h,w,a,b;
cin >> h>>w>>a>>b;
COMinit();
rep(i,h-a){
    ans+=COM(b-1+i,i)*COM(h+w-b-2-i,w-b-1)%mo;
    //cout << COM(b-1+i,i) <<" "<< COM(h+w-b-2-i,h-i)<< endl;
    ans%=mo;
}

cout << ans << endl;
return 0;
}
