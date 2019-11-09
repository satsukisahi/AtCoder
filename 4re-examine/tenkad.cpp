#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=998244353;
ll ans=0;
ll dp[301][90001]={};
ll dp2[301][90001]={};

int main()
{
ll n;
cin >> n;
ll table[n]={};
rep(i,n) {
    cin >> table[i];
}
ll sum=0;
rep(i,n){
    sum+=table[i];
}
bool a=1;
if(sum%2==1)a=0;
sum=(sum-1)/2;
dp[0][0]=1;
dp2[0][0]=1;
ll maxa=1;
rep(i,n){rep(j,maxa){
    dp[i+1][j]+=2*dp[i][j];
    dp[i+1][j]=dp[i+1][j]%mo;
    dp2[i+1][j]+=dp2[i][j];
    dp2[i+1][j]=dp2[i+1][j]%mo;
    dp[i+1][j+table[i]]+=dp[i][j]; 
    dp[i+1][j+table[i]]=dp[i+1][j+table[i]]%mo;
    dp2[i+1][j+table[i]]+=dp2[i][j]; 
    dp2[i+1][j+table[i]]=dp2[i+1][j+table[i]]%mo;
}
maxa=maxa+table[i];
}
for(int i=sum+1;i<maxa;i++){
    ans+=3*dp[n][i];
    ans=ans%mo;
}
if(a){
    ans=ans-dp2[n][sum+1]*6/2;
}
ll jyo=1;
rep(i,n){
    jyo=3*jyo;
    jyo=jyo%mo;
}
ans=jyo+mo-ans;
ans=ans%mo;

cout << ans << endl;
return 0;
}






