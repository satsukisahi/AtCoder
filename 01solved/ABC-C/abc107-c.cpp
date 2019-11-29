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
int ans=300000000;
//整数値の入力
int n,k;
cin >> n >>k;
//行列の入力
int table[n]={};
for (int i = 0; i < n; ++i) {
    cin >> table[i];
}

int lastfu=-1;
for (int i = 0; i < n; ++i) {
    if(table[i]<0){lastfu++;}
}

int start=0,temp=0;
//cout << lastfu << endl;
if (lastfu+2>k){start=lastfu-k+2;}
for(int i = 0; i < k; ++i) {

    if(table[start]>0){temp=table[start+k-1];}
    else{temp=min(abs(table[start])+2*abs(table[start+k-1]),2*abs(table[start])+abs(table[start+k-1]));}
   // cout << temp << endl;
    if(temp<ans){ans=temp;}
    start++;
    if(start+k>n){break;}
}
if(lastfu==n-1){ans=-1*table[n-k];}

//回答
cout << ans << endl;
return 0;
}


// b^nを計算する関数
int mypow(int b, int n) {
    if (n == 0) return 1;
    if (n == 1) return b;
    if (n % 2 == 0) {
        return mypow(b * b, n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}
