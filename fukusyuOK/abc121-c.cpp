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

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
void sort2(vector<pair<ll, ll> >& pairs,ll n){
     // b順にソート
    sort(pairs.begin(),pairs.end(), compare_by_b);
for(ll i=0; i<n; i++){
    
}}


int main()
{
//回答が整数の場合
ll ans=0;
//整数値の入力
ll n,m;
cin >> n>>m;

vector<pair<ll, ll> > pairs(n);

// 入力
for(ll i=0; i<n; i++){
    ll a, b;
    cin >> a >> b;
    pairs[i] = make_pair(b, a);
}
sort2(pairs,n);
ll buy=0;
for(ll i=0; i<n; i++){
   // cout << pairs[i].first << " "<<pairs[i].second <<" "<< buy << " "<<ans<< endl;
    if(buy+pairs[i].first>=m){ans=ans+(pairs[i].second*(m-buy));break;}
    else{ans=ans+(pairs[i].first*pairs[i].second);buy=buy+pairs[i].first;}
}

//回答
cout << ans << endl;
return 0;
}



