#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll dp[100100][13]={};
int main()
{
string s;
cin >> s;
int len=(int)(s.length());
dp[0][0]=1;
ll jyu=1;
rep(i,len){
    if(s[len-1-i]=='?'){
        rep(k,10){
            ll num=k;
            rep(j,13){
                ll p=num*jyu+j;
                p%=13;
                dp[i+1][p]+=dp[i][j];
                dp[i+1][p]%=mo;
        }
        }
    }
    else{
        rep(j,13){
            ll num=s[len-1-i]-'0';
            ll p=num*jyu+j;
            p%=13;
            dp[i+1][p]+=dp[i][j];
            dp[i+1][p]%=mo;
        }
    }
    jyu*=10;
    jyu%=13;
}

cout << dp[len][5] << endl;
return 0;
}
