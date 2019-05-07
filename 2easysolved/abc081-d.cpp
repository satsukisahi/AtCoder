#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;


int main()
{ 
ll n;
cin >> n; 
ll t[n]={};
ll tt[n]={};
rep(i,n) {
    cin >> t [i];
    tt [i]=t[i];
}
sort(tt,tt+n);
if(tt[0]*(-1)<tt[n-1]){
    ll pos;
    rep(i,n){
        if(t[i]==tt[n-1])pos=i;
    }
    cout << 2*n-2 << endl;
    cout << pos+1<<' '<< 2<< endl;
    cout << pos+1<<' '<< 2<< endl;
    rep(i,n-2){
        cout << i+2<<' '<< i+3<< endl;
        cout << i+2<<' '<< i+3<< endl;
    }
}
else{
    ll pos;
    rep(i,n){
        if(t[i]==tt[0])pos=i;
    }
    cout << 2*n-2 << endl;
    cout << pos+1<<' '<< n-1<< endl;
    cout << pos+1<<' '<< n-1<< endl;
    rep(i,n-2){
        cout << n-1-i<<' '<< n-2-i<< endl;
        cout << n-1-i<<' '<<n-2-i<< endl;
    }
}


return 0;
} 