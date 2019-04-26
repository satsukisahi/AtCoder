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
ll n;
cin >> n;
vector<int> ans;
vector<int> table(n);
for(int i = 0; i < n; i++) {
    cin >> table[i];
}
ll nok=n;
bool aa=true;
while(aa){

    aa=false;
    rep(i,nok){
        if(table[nok-i-1]==nok-i){
            ans.push_back(nok-i);
            table.erase(table.begin() + nok-i-1);
            nok=nok-1;
            aa=1;
            if(nok==0){aa=false;}        
            break;          
        }      
    }
}

if(ans.size()==n){
    rep(i,n){
        cout << ans[n-i-1]<< endl;
    }
}
else
{
    cout << -1 << endl;
}


return 0;
}



