#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
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
ll r,c,x,y,d,l;
cin >> r>>c>>x>>y>>d>>l;
COMinit();
ll ba=COM(x*y,d);
ba%=mo;

if(d+l!=x*y){
ba*=COM(x*y-d,l);
ba%=mo;
rep(i,1LL<<4){
    if(i==0)continue;
    ll tx=x;
    ll ty=y;
    if((i>>0&1)==1)tx--;
    if((i>>1&1)==1)tx--;
    if((i>>2&1)==1)ty--;
    if((i>>3&1)==1)ty--;
    if(tx<0||ty<0)continue;
    if(__builtin_popcountll(i)%2){
        ba-=COM(tx*ty,d)*COM(tx*ty-d,l);
        ba=ba+(ba/mo-1)*(-mo);
        ba%=mo;
    }
    else{
        ba+=COM(tx*ty,d)*COM(tx*ty-d,l);
        ba%=mo;
    }
}

}
ba*=(r-x+1)*(c-y+1);
ba%=mo;
cout << ba << endl;
return 0;
}
