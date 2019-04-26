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
string n;
cin >> n;

int len=(int)(n.length());
int zero=0;
int ichi=0;
for(int i=0;i<len;i++){
  if(n[i]=='0'){zero++;}
  if(n[i]=='1'){ichi++;}

}

if(zero>ichi){ans=ichi*2;}
else{ans=zero*2;}

//回答
cout << ans << endl;
return 0;
}

