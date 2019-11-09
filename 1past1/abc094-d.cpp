#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{ 
ll n;
cin >> n; 
ll table[n]={};
rep(i,n) {
    cin >> table [i];
}
sort(table, table+n);
cout << table[n-1] << ' ';
ll te=abs(table[n-1]/2+1-table[0]);
ll tem;
rep1(i,n-1){
    if(table[n-1]%2){
    tem=abs(table[n-1]/2+1-table[i]);
    if(tem<te){te=tem;ans=i;}
    }
    else{
        tem=abs(table[n-1]/2-table[i]);
        if(tem<te){te=tem;ans=i;}
    }
}

cout << table[ans] << endl;
return 0;
} 