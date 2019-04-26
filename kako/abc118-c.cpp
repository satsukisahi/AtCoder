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
int ans;
//整数値の入力
int n;
cin >> n;
//行列の入力
int table[n]={};
for (int i = 0; i < n; ++i) {
    cin >> table[i];
}
for (int i = 0; i < n-1; ++i) {
    table[i+1]=__gcd(table[i],table[i+1]);
}

//回答
cout << table[n-1] << endl;
return 0;
}