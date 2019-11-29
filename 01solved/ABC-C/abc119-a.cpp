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
string ans;
//整数値の入力
int y,m,d;
char st,stt;
cin >> y>> st>> m>> stt>> d;
//行列の入力
if(m>4){ans="TBD";}
else{ans="Heisei";}
//回答
cout << ans << endl;
return 0;
}

