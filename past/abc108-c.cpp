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
long long int ans=0;
long long int a1=0;
long long int b1=0;
//整数値の入力
int n,k;
cin >> n >> k;

a1=n/k;
b1=(n+k/2)/k;

if(k%2==1){ans=(a1)*(a1)*(a1);}
else{
    ans=(a1)*(a1)*(a1)+(b1)*(b1)*(b1);
}

//回答
cout << ans << endl;
return 0;
}

