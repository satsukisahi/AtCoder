#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
int mypow(int b, int n) {
    if (n <= 0) return 1;
    if (n == 1) return b;
    if (n % 2 == 0) {
        return mypow(b * b, n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

int main()
{
ll ans,h,w,k,aa;
ll mo=1000000007;
cin >> h>>w>>k;
ll dp[h+1][w]={};
dp[0][0]=1;
ll id[w][3]={};
ll idd[8]={1,2,3,5,8,13,21,34};

if(w==1){
    ans=1;
}
else{

//0から2^d乗まで
for (int bit = 0; bit < (1<<w-1); ++bit) {
    bool ng=1;
    
//各ビットを下から見ていく
     rep(j,w-1){

//jビット目が1なら処理を行う
        if(bit>>j&1){
            if(j!=w-2&&bit>>(j+1)&1){ng=0;}
        }
    }
    rep(j,w-1){

//jビット目が1なら処理を行う
        if(bit>>j&1&&ng){
            id[j][2]++;
            id[j+1][1]++;
        }
    }
}
rep(i,w){
    id[i][0]=idd[w-1]-id[i][2]-id[i][1];
}

rep(i,h)rep(j,w){
    if(j==0){
        dp[i+1][j]=(dp[i+1][j]+dp[i][j]*id[j][0])%mo;
        dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*id[j][2])%mo;
    }
    else if(j==w-1){
        dp[i+1][j]=(dp[i+1][j]+dp[i][j]*id[j][0])%mo;
        dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j]*id[j][1])%mo;
    }
    else{
        dp[i+1][j]=(dp[i+1][j]+dp[i][j]*id[j][0])%mo;
        dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*id[j][2])%mo;
        dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j]*id[j][1])%mo;
    }
}
ans=dp[h][k-1];
}
/* 
for (int i = 0; i < w; ++i) {
    cout << id[i][0] << " ";
}cout  << endl;
for (int i = 0; i < w; ++i) {
    cout << id[i][1] << " ";
}cout  << endl;
for (int i = 0; i < w; ++i) {
    cout << id[i][2] << " ";
}cout  << endl; */

cout <<ans<< endl;
return 0;
}



