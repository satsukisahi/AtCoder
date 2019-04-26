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
ll ans,n,k,temp;

cin >> n>>k;
vector<ll> syu(100002,0);
vector<ll> nokori;
ll dp[n]={};
rep(i,n){
    ll t,d;
    cin >>t>>d;
    if(syu[t]>d)nokori.push_back(d);
    else{nokori.push_back(syu[t]);syu[t]=d;}
}
sort(syu.rbegin(), syu.rend());
sort(nokori.rbegin(), nokori.rend());
ans=syu[0]+1;
rep(i,k-1){
    ans+=nokori[i];
}
temp=ans;
//cout << temp << endl;
rep(i,k-1){
    if(syu[i+1]==0)break;
    temp=temp+syu[i+1]-nokori[k-i-2]+(i+2)*(i+2)-(i+1)*(i+1);
    //cout << temp << endl;
    if(temp>ans)ans=temp;
}
/* for (int i = 0; i < n; ++i) {
    cout << syu[i] << " ";
}cout  << endl;
for (int i = 0; i < n; ++i) {
    cout << nokori[i] << " ";
}cout  << endl; */
cout << ans << endl;
return 0;
}



