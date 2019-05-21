#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll m,k;
cin >> m>>k;
if(m==0&&k==0){
    cout << "0 0" << endl;
    return 0;
}
if(m==0){
    cout << "-1" << endl;
    return 0;
}
if(m==1&&k==0){
    cout << "0 0 1 1" << endl;
    return 0;
}
if(m==1){
    cout << "-1" << endl;
    return 0;
}
if(k>=(1LL<<m)){
    cout << "-1" << endl;
    return 0;
}
rep(i,1LL<<m){
    if((1LL<<m)-i-1!=k)cout << (1LL<<m)-i-1<<" " ;
}
cout << k <<" " ;
rep(i,1LL<<m){
    if(i!=k)cout << i<<" " ;
}
cout << k << endl;
return 0;
}