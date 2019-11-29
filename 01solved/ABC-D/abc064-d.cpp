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
ll n;
string s;
cin >> n>>s;
ll a=0,b=0;
rep(i,n){
    if(s[i]=='('){a++;}
    else{a--;if(a<0)a=0;}
}
rep(i,n){
    if(s[n-1-i]==')'){b++;}
    else{b--;if(b<0)b=0;}
}
rep(i,a){
    s=s+')';
}
rep(i,b){
    s='('+s;
}

cout << s << endl;
return 0;
}