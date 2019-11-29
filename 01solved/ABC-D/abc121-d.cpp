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
ll a,b;
cin >> a>>b;
//回答が整数の場合
ll ans=0;

if(a%2LL){
    if(((b-a)%4LL)==0LL){ans=a;}
    else if(((b-a)%4LL)==1LL){ans=a^b;}
    else if(((b-a)%4LL)==2LL){ans=a^1LL;}
    else {ans=(a^b)^1LL;}
}
else{
    if(((b-a)%4LL)==0LL){ans=b;}
    else if(((b-a)%4LL)==1LL){ans=1LL;}
    else if(((b-a)%4LL)==2LL){ans=b^1LL;}
    else {ans=0;}
}

//回答
cout << ans << endl;
return 0;
}



