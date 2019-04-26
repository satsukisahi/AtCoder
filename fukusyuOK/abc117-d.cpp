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


int main()
{
//回答が整数の場合
ll ans=-1;
//整数値の入力
ll n,k;
cin >> n>>k;
//行列の入力
ll table[n]={};
for (int i = 0; i < n; ++i) {
    cin >> table[i];
}

int ichi[40]={};
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 40; ++j) {   
     if((table[i]>>j)&1LL){ichi[j]++;}
}
}

//反転すべき時1でそのままの時0
for (int j = 0; j < 40; ++j) { 
    if(ichi[j]<=n/2){ichi[j]=1;}
    else{ichi[j]=0;}
}
ll dp[40]={};
//dpまわす
int syu=1;
for (int j = 0; j < 40; ++j) {
    for(int i = 1 ; i < syu; ++i){
        if(ichi[39-j]){
        dp[i]=dp[i]+(1LL<<(39-j));
        }
    }
    if(ichi[39-j]&&(dp[0]+(1LL<<(39-j))<=k)){
        dp[syu]=dp[0];
        dp[0]=dp[0]+(1LL<<(39-j));
        syu=syu+1;
    }
}
ll f;
for (int i = 0; i < 40; ++i) {
    ll sum=0;
    for (int j = 0; j < n; ++j) {
    sum=sum+(dp[i]^table[j]);
    }
    if(ans<sum){ans=sum;f=dp[i];}

}

/* for (int i = 0; i < 40; ++i) {
    cout << dp[i] << " ";
} cout <<  endl; */

//cout << f << " "<< ans<< endl;
cout << ans<< endl;
return 0;
}



