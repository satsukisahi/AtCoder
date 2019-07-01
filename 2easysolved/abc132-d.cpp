#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll ans2 = 0;
    ll mypow(ll a,ll b){
        ll res=1;
        a%=mo;
        while(b){
            if(b&1)
                res=res*a%mo;
            a=a*a%mo;
            b>>=1;
        }
        return res;
    }
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
ll n,k;
cin >> n>>k;
    vector<ll> kaij;
    kaij.push_back(1);
    for(ll i = 1; i < k+5; i++){
        kaij.push_back((kaij[i-1]*i)%mo);
    }
COMinit();
rep(i,k){
    ans=COM(n-k+1,i+1);
    ans*=kaij[k-1];
    ans%=mo;
    ans*=mypow((kaij[k-i-1]*kaij[i])%mo,mo-2);
    ans%=mo;
    cout << ans <<endl;
}
return 0;
}
