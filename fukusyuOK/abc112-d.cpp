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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
//素数判定
bool prime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
int main()
{
ll ans=0,n,m;

cin >> n>>m;


vector<int> soin;
double sqrtNum = sqrt(m);
for (int i = 1; i <= sqrtNum; i++){
    if(m%i==0){soin.push_back(i);soin.push_back(m/i);}
}
sort(soin.begin(), soin.end());
/* for (int i = 0; i < soin.size(); ++i) {
    cout << soin[i] << " ";
}cout  << endl; */

rep(i,soin.size()){
    if(n<=soin[i]){ans=soin[i];break;}
}
ans=m/ans;
cout << ans << endl;
return 0;
}



