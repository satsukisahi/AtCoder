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
ll ans,n,k;

cin >> n>>k;

int table[n]={};
rep(i,n) {
    cin >> table[i];
}
ans=(n-1)/(k-1)+1;
if((n-1)%(k-1)==0)ans--;

cout << ans << endl;
return 0;
}



