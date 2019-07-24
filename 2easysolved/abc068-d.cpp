#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll k;
cin >> k;
if(k==1){
    cout << 2 << endl;
    cout << 0 <<  " " << 2 << endl;
    return 0;
}
if(k==0){
    cout << 2 << endl;
    if(k%2){
        cout << k <<  " " << 1 << endl;
    }
    else{
        cout << k+1 <<  " " << 0 << endl;
    }
    return 0;
}
ll sy=k/50;
ll am=k%50;
vector<ll> v;
rep(i,am)v.push_back(100-am);
rep(i,50-am)v.push_back(49-am);
rep(i,50){
    v[i]+=sy;
}

cout << 50 << endl;
for (auto& u : v) {
    cout << u << " ";
}cout  << endl;
return 0;
}
