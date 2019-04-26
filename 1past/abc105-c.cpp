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
//2の補数問題
int main()
{
vector<int> hoge;
ll n,a=2;
cin >> n;
while(true){
if(n%abs(a)!=0){
    n=n-a/2;
    hoge.push_back(1);;a=a*(-2);
    }
else {hoge.push_back(0);a=a*(-2);}
if(n==0)break;
}
rep(i,hoge.size()){
    cout<<hoge[hoge.size()-1-i];
}
return 0;
}



