#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;

int main()
{
string s;
cin >> s;
ll len=(int)(s.length());
ll dp[len][4]={};
if(s[0]=='A'){dp[0][0]=1;dp[0][1]=1;}
else if(s[0]=='?'){dp[0][0]=3;dp[0][1]=1;}
else {dp[0][0]=1;}
string abc="ABCZ";
rep(i,len-1)rep(j,4){
    if(s[i+1]=='?'){
        dp[i+1][j]+=3*dp[i][j];
        dp[i+1][j]=dp[i+1][j]%mo;
        if(j!=3){dp[i+1][j+1]+=dp[i][j];dp[i+1][j+1]=dp[i+1][j+1]%mo;}
        }
    else if(s[i+1]==abc[j]){
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j]=dp[i+1][j]%mo;
        dp[i+1][j+1]+=dp[i][j];
        dp[i+1][j+1]=dp[i+1][j+1]%mo;
    }
    else {
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j]=dp[i+1][j]%mo;
    }
}
/* for (int i = 0; i < 4; ++i){
for (int j = 0; j < 4; ++j) {
    cout << dp[i][j] << " ";
}cout  << endl;} */

cout << dp[len-1][3] << endl;
return 0;
}






