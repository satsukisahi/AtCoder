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
ll ans,n;

cin >> n;

int table[n]={};
rep(i,n) {
    cin >> table[i];
}
ll sum=0;
rep(i,n) {
    sum+=table[i];
}
ans=sum-n;
cout << ans << endl;
return 0;
}



