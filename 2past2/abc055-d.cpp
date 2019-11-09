#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n;
cin >> n;
string s;
cin >> s;
char ans[n+1];


ans[0]='S';
ans[1]='S';

for(ll i=2;i<n+1;i++){
    if(ans[i-1]=='S'&&s[i-1]=='o')ans[i]=ans[i-2];
    else if(ans[i-1]=='W'&&s[i-1]=='x')ans[i]=ans[i-2];
    else if(ans[i-2]=='W')ans[i]='S';
    else ans[i]='W';
}
if(ans[0]==ans[n]&&((s[0]=='x'&&ans[1]!=ans[n-1])||(s[0]=='o'&&ans[1]==ans[n-1]))){
    rep(i,n){
        cout << ans[i];
    }
    cout  << endl;
    return 0;
}
ans[0]='S';
ans[1]='W';
for(ll i=2;i<n+1;i++){
    if(ans[i-1]=='S'&&s[i-1]=='o')ans[i]=ans[i-2];
    else if(ans[i-1]=='W'&&s[i-1]=='x')ans[i]=ans[i-2];
    else if(ans[i-2]=='W')ans[i]='S';
    else ans[i]='W';
}
if(ans[0]==ans[n]&&((s[0]=='x'&&ans[1]!=ans[n-1])||(s[0]=='o'&&ans[1]==ans[n-1]))){
    rep(i,n){
        cout << ans[i];
    }
    cout  << endl;
    return 0;
    return 0;
}
ans[0]='W';
ans[1]='W';
for(ll i=2;i<n+1;i++){
    if(ans[i-1]=='S'&&s[i-1]=='o')ans[i]=ans[i-2];
    else if(ans[i-1]=='W'&&s[i-1]=='x')ans[i]=ans[i-2];
    else if(ans[i-2]=='W')ans[i]='S';
    else ans[i]='W';
}
if(ans[0]==ans[n]&&((s[0]=='x'&&ans[1]==ans[n-1])||(s[0]=='o'&&ans[1]!=ans[n-1]))){
    rep(i,n){
        cout << ans[i];
    }
    cout  << endl;
    return 0;
    return 0;
}
ans[0]='W';
ans[1]='S';
for(ll i=2;i<n+1;i++){
    if(ans[i-1]=='S'&&s[i-1]=='o')ans[i]=ans[i-2];
    else if(ans[i-1]=='W'&&s[i-1]=='x')ans[i]=ans[i-2];
    else if(ans[i-2]=='W')ans[i]='S';
    else ans[i]='W';
}
if(ans[0]==ans[n]&&((s[0]=='x'&&ans[1]==ans[n-1])||(s[0]=='o'&&ans[1]!=ans[n-1]))){
    rep(i,n){
        cout << ans[i];
    }
    cout  << endl;
    return 0;
    return 0;
}


cout << -1 << endl;
return 0;
}