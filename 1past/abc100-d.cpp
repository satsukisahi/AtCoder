#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[1010][1010][8];

int main()
{ 
rep(i,1010)rep(j,1010)rep(k,8){
    dp[i][j][k]=-9999999999999999;
}
ll n,m;
cin >> n>>m; 
ll table[n][3]={};
rep(i,n) {
    cin >> table[i][0]>>table [i][1]>> table[i][2];
}
rep(i,8){
dp[0][0][i]=0;
}
rep(i,n+1)rep(j,m+1){
    //採択しない
    rep(k,8){
        if(dp[i][j][k]>=0)dp[i+1][j][k]=max(dp[i][j][k],dp[i+1][j][k]);
    }
    //0以上なら採択
    if(j!=m){
        dp[i+1][j+1][0]=max(dp[i][j][0]+table[i][0]+table[i][1]+table[i][2],dp[i+1][j+1][0]);
    }
    if(j!=m){
        dp[i+1][j+1][1]=max(dp[i][j][1]+table[i][0]+table[i][1]-table[i][2],dp[i+1][j+1][1]);
    }
    if(j!=m){
        dp[i+1][j+1][2]=max(dp[i][j][2]+table[i][0]-table[i][1]+table[i][2],dp[i+1][j+1][2]);
    }
    if(j!=m){
        dp[i+1][j+1][3]=max(dp[i][j][3]+table[i][0]-table[i][1]-table[i][2],dp[i+1][j+1][3]);
    }
    if(j!=m){
        dp[i+1][j+1][4]=max(dp[i][j][4]-table[i][0]+table[i][1]+table[i][2],dp[i+1][j+1][4]);
    }
    if(j!=m){
        dp[i+1][j+1][5]=max(dp[i][j][5]-table[i][0]+table[i][1]-table[i][2],dp[i+1][j+1][5]);
    }
    if(j!=m){
        dp[i+1][j+1][6]=max(dp[i][j][6]-table[i][0]-table[i][1]+table[i][2],dp[i+1][j+1][6]);
    }
    if(j!=m){
        dp[i+1][j+1][7]=max(dp[i][j][7]-table[i][0]-table[i][1]-table[i][2],dp[i+1][j+1][7]);
    }
}
rep(i,8){
    ans=max(dp[n][m][i],ans);
}
//2次元配列の中身を見る

/* for (int i = 0; i < n; ++i){
for (int j = 0; j < m; ++j) {
    cout << dp[i][j][2] << " ";
}cout  << endl;} */

cout << ans << endl;
return 0;
} 