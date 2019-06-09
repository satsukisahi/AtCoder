#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
string n;
cin >> n;
int len=(int)(n.length());

ll dp[len][2]={};
dp[0][0]=2;
dp[0][1]=1;

rep1(i,len){
    if(n[i]=='1'){
        dp[i][0]=dp[i-1][0]*2;
        dp[i][0]%=mo;
        dp[i][1]=dp[i-1][0]+dp[i-1][1]*3;
        dp[i][1]%=mo;
    }
    if(n[i]=='0'){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1]*3;
        dp[i][1]%=mo;
    }
}

ans=dp[len-1][0]+dp[len-1][1];
ans%=mo;
cout << ans << endl;
return 0;
}