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

int main()
{
ll ans=0,n;
cin >> n;
int table[n]={};
rep(i,n) {
    cin >> table[i];
}

rep(i,n) {
    table[i]+=n-i;
}
sort(table,table+n);
ll me=table[n/2];

rep(i,n) {
    ans+=abs(table[i]-me);
}
cout << ans << endl;
return 0;
}



