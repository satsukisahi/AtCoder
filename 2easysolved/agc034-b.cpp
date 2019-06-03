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
string s;
cin >> s;
int n=(int)(s.length());
ll t[n]={};
rep(i,n-1){
    if(s[i]=='B')if(s[i+1]=='C'){
        t[i]=1;
    }
    if(s[i]=='B')if(s[i+1]=='B'){
        t[i]=-1;
    }
    if(s[i]=='B')if(s[i+1]=='A'){
        t[i]=-1;
    }
    if(s[i]=='A')if(s[i+1]=='C'){
        t[i]=-1;
    }
    if(s[i]=='C')if(s[i+1]=='C'){
        t[i]=-1;
    }
}

/* for (int i = 0; i < n; ++i) {
    cout << t[i] << " ";
}cout  << endl; */

rep(i,n){
    if(t[n-i-2]==-1)t[n-i-2]=0;
    else t[n-i-2]+=t[n-i-1];
}
rep(i,n){
    if(s[i]=='A')ans+=t[i];
}

/* for (int i = 0; i < n; ++i) {
    cout << t[i] << " ";
}cout  << endl; */

cout << ans << endl;
return 0;
}