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
ll n,a,b,c,d;
cin >> n>>a>>b>>c>>d;
a--;b--;c--;d--;
string s;
cin >> s;
for(ll i=a;i<max(c,d);i++){
    if(s[i]=='#'&&s[i+1]=='#'){
        cout << "No" << endl;
        return 0;
    }
}
if(c<d){
    cout << "Yes" << endl;
    return 0;
}
for(ll i=b;i<=d;i++){
    if(s[i]=='.'&&s[i-1]=='.'&&s[i+1]=='.'){
        cout << "Yes" << endl;
        return 0;
    }
    
}

cout << "No" << endl;
return 0;
}