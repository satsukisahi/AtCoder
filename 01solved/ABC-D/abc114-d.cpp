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
ll ans,n,temp;

cin >> n;
vector<int> v(101, 0); 
for(ll i = 2; i <= n; i++){
    if(prime(i)){v[i]++;}
    else{
        temp=i;
        for(ll j = 0; j <= temp; j++){
            if(prime(j)&&(temp%j==0)){
                temp=temp/j;v[j]++;j--;
            }
        if(temp==1)break;
        }
    }
}
ll up24=0,up14=0,up4=0,up2=0;
rep(i,50){
    if(v[i]>1){up2++;
    if(v[i]>3){up4++;
    if(v[i]>13){up14++;
    if(v[i]>23){up24++;
    }}}}
}
ans=(up4-1)*up4*(up2-2)/2+up24*(up2-1)+up14*(up4-1);
/* for (int i = 0; i <= n; ++i) {
    cout << v[i] << " ";
}cout  << endl; */
if(n>77)ans++;
cout << ans << endl;
return 0;
}



