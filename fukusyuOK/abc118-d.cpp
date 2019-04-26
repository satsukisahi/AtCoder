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

//整数値の入力
int n,m;
cin >> n>>m;
int honsu[10]={-1,2,5,5,4,5,6,3,7,6};
int table[m]={};
for (int i = 0; i < m; ++i) {
    cin >> table[i];
}
vector<int> dp(n+10,-100000);
dp[0]=0;
sort(table,table+m);
//最大桁数求める
//配るDP回す
for (int i = 0; i < n; ++i) {
for (int j = m-1; j >-1; --j) {
    dp[i+honsu[table[j]]]=max(dp[i]+1,dp[i+honsu[table[j]]]);
}
}

//cout << dp[n];
int use=0;
//最大の使える数字から使ってみてdp[n-使った本数]がdp[n]-１かチェック
while(use<n){
   // cout << use;
for(int j = m-1; j >-1; --j) {
    if(dp[n-use-honsu[table[j]]]==dp[n-use]-1&&n-use-honsu[table[j]]>-1){
        use=use+honsu[table[j]];
        cout << table[j];
        break;
        }
}
}



return 0;
}



