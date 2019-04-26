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
char s[100];
cin >> s;

int k;
cin >> k;
char ans='1';
int num1=0;

for(int i=0;i<strlen( s );++i){
    if(s[i]!='1'){ans=s[i];break;}
    num1++;
}

if(num1>k-1){ans='1';}
//回答
cout << ans << endl;
return 0;
}

