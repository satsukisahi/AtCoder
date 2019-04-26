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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
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
ll ans,q;

cin >> q;

int table[100002]={};


for(int i = 2; i < (int)(100002); i++){
    if(prime(i)&&prime((i+1)/2)){
        table[i]=table[i-1]+1; 
    }
    else{
        table[i]=table[i-1];
    }
}

int l,r;
rep(i,q){
    cin >> l>>r;
    ans=table[r]-table[l-1];
    cout << ans << endl;
}
return 0;
}



