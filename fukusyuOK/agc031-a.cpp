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
ll ans=1;
//整数値の入力
int n;
cin >> n;
//行列の入力
char table[n]={};
for (int i = 0; i < n; ++i) {
    cin >> table[i];
}
sort(table, table+n);
int al[26]={};
al[0]++;
int syu=0;
for (int i = 0; i < n-1; ++i) {
    if(table[i]==table[i+1]){al[syu]++;}
    else{syu++;al[syu]++;}
}
for (int i = 0; i < 26; ++i) {
    ans=ans*(al[i]+1);
    ans=ans%1000000007;
 
}

//回答
cout << ans-1 << endl;
return 0;
}
