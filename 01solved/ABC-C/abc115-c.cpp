#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
//回答が整数の場合
int ans=1000000000;
//整数値の入力
int n,k;
cin >> n >>k;
//行列の入力
int table[n]={};
for (int i = 0; i < n; ++i) {
    cin >> table[i];
}

sort(table, table + n);
for (int i = 0; i < n-k+1; ++i) {
    if(ans>table[i+k-1]-table[i]){ans=table[i+k-1]-table[i];}
}


//回答
cout << ans << endl;
return 0;
}