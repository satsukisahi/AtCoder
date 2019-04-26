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
int ans=0;
//整数値の入力
int n,m,i;
cin >> n >> m;
//行列の入力
int table[m]={};
for (int i = 0; i < m; ++i) {
    cin >> table[i];
}

sort(table, table + m);
int table1[m-1]={};

for(i=0;i<m-1;++i){
    table1[i]=table[i+1]-table[i];
}
sort(table1, table1 + (m-1));
for(i=0;i<m-n;++i){
    ans=ans+table1[i];
}


//回答
cout << ans << endl;
return 0;
}