#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
string s;
cin >> s;
int len=(int)(s.length());
ll w=0;
rep(i,len){
    if(s[i]=='W'){
        ans+=i-w;
        w++;
    }
}

cout << ans << endl;
return 0;
}
