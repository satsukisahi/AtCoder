#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=1;
ll dp[0][0];


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


bool prime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
int main()
{
ll n,m;
if(m==1){cout << '1' << endl;return 0;}
cin >> n>>m;
int tempsoin=m;
vector<int> soin;
for(ll j = 2; j <= tempsoin; j++){
    if(tempsoin%j==0){
        tempsoin=tempsoin/j;
        soin.push_back(j);
        j--;
    }
if(prime(tempsoin)){
    soin.push_back(tempsoin);
    break;
    }
}
soin.push_back(0);
ll coun[100000]={};
ll syu=0;
rep(i,soin.size()-1){
    coun[syu]++;
    if(soin[i]!=soin[i+1])syu++;
}
vector<ll> kaij;
kaij.push_back(1);
for(ll i = 1; i < 100100; i++){
    kaij.push_back((kaij[i-1]*i)%1000000007);
}
COMinit();

rep(i,syu){
    ans=ans*COM(coun[i]+n-1,coun[i])%mo;
}

cout << ans << endl;
return 0;
}



