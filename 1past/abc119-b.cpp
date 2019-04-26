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
double ans=0;
//整数値の入力
int n;
cin >> n;
double table;

for (int i = 0; i < n; ++i) {
    cin >> table;
    string tani;
    cin >> tani;
    if(tani=="BTC"){table=table*380000;}
    ans=ans+table;
   // cout << table << endl;
}
//回答
cout << ans << endl;
return 0;
}

