#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll anss=0;

int main()
{
ll n,m;
cin >> n>>m;

bool t[10][10]={};
ll k;
rep(i,m){
    
    cin >> k;
    rep(j,k){
        ll a;
        cin >> a;
        t[i][a-1]=true;
    }
}

ll ans[m];

rep(i,m){
    ll ki;
    cin >> ki;
    ans[i]=ki;
}

//0から2^d乗まで
for (int bit = 0; bit < (1<<n); ++bit) {

    ll ch[m]={};
    
//各ビットを下から見ていく
    rep(j,n){

//jビット目が1なら処理を行う
        if(bit>>j&1){
            rep(ii,m){
                if(t[ii][j])ch[ii]++;
            }
            
        }
    }
    bool chh=1;
    rep(i,m){
        if(ans[i]!=ch[i]%2)chh=0;
    }
    if(chh)anss++;
}
cout << anss << endl;
return 0;
}