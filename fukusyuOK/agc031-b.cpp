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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
ll ans,n;

cin >> n;

int table[n+1]={};
table[0]=-1;
rep(i,n) {
    cin >> table[i+1];
}
ll dp[n+1]={};
dp[0]=1;
ll re[200001]={};
ll temp;
for(int i = 1; i < n+1; i++){
    if(table[i]!=table[i-1]){
        dp[i]=(re[table[i]]+dp[i-1])%1000000007;
        re[table[i]]+=dp[i-1];
    }
    else dp[i]=dp[i-1];
    
}
//配列の中身を見る

/* for (int i = 0; i < n+1; ++i) {
    cout << dp[i] << " ";
}cout  << endl;
for (int i = 0; i < n+1; ++i) {
    cout << re[i] << " ";
}cout  << endl; */

cout << dp[n] << endl;
return 0;
}

