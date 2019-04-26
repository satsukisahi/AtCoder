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
ll a=0,c=0,q=0;
rep(i,len){
    if(s[i]=='C')c++;
    if(s[i]=='?')q++;
}
dp[0][2]=c;
dp[0][3]=q;
if(s[0]=='C')dp[0][2]--;
if(s[0]=='?')dp[0][3]--;

rep(i,len){
    
    if(s[i]=='A')dp[i+1][0]=dp[i][0]+1;
    else dp[i+1][0]=dp[i][0];
    if(s[i]=='?')dp[i+1][1]=dp[i][1]+1;
    else dp[i+1][1]=dp[i][1];
    if(i==0)continue;
    if(s[i]=='C')dp[i][2]=dp[i-1][2]-1;
    else dp[i][2]=dp[i-1][2];
    if(s[i]=='?')dp[i][3]=dp[i-1][3]-1;
    else dp[i][3]=dp[i-1][3];
}
ll jyo[100002];
jyo[2]=1;
jyo[1]=0;
jyo[0]=0;
rep(i,99999){
    jyo[i+3]=(jyo[i+2]*3)%mo;
}

/* for (int i = 0; i < len; ++i) {
    cout << dp[i][0] << " "<< dp[i][1] << " "<< dp[i][2] << " "<< dp[i][3] << endl;
} */

for(ll i = 1; i < len-1; i++){
    if(s[i]=='B'||s[i]=='?')ans+=(((dp[i][0]*jyo[dp[i][1]+2]+dp[i][1]*jyo[dp[i][1]+1])%mo)*((dp[i][2]*jyo[dp[i][3]+2]+dp[i][3]*jyo[dp[i][3]+1])%mo))%mo;
    
}
ans=ans%mo;


cout << ans << endl;
return 0;
}






