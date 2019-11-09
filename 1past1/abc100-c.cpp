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
ll ans=0,n;

cin >> n;

int table[n]={};
rep(i,n) {
    cin >> table[i];
}
rep(i,n){
int tempsoin=table[i];
for(ll j = 2; j <= tempsoin; ){
    if(tempsoin%j==0){
        tempsoin=tempsoin/j;
        ans++;
        
    }
    else break;
}}

cout << ans << endl;
return 0;
}



