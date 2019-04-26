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

int main()
{
ll ans,n;

cin >> n;
ans=n*(n-1)/2-n/2;
cout << ans << endl;
if(n%2){
    for(int i = 1; i < n+1; i++){
        for(int j = i+1;  j< n+1; j++){
            if(i+j!=n)cout << i<< " "<<j << endl;
        }
    }
}
else{
    for(int i = 1; i < n+1; i++){
        for(int j = i+1;  j< n+1; j++){
            if(i+j!=n+1){cout << i<< " "<<j << endl;}
        }
    }
}

return 0;
}



