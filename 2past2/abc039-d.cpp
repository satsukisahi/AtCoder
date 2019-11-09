#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll h,w;
cin >> h>>w;
string s[h];
string ans[h];
string test[h];
rep(i,h){
    cin >> s[i];
}
rep(i,h)rep(j,w){
    bool ok=1;
    rep(k,3)rep(l,3){
        if(i+k-1>=0&&j+l-1>=0&&i+k-1<h&&j+l-1<w&&s[i+k-1][j+l-1]=='.')ok=0;
    }
    if(ok){
        ans[i]+="#";
        test[i]+="#";
    }
    else {
        ans[i]+=".";
        test[i]+=".";
    }
}
rep(i,h)rep(j,w){
    if(ans[i][j]=='#')
    rep(k,3)rep(l,3){
        if(i+k-1>=0&&j+l-1>=0&&i+k-1<h&&j+l-1<w)test[i+k-1][j+l-1]='#';
    }
}
rep(i,h){
    if(s[i]!=test[i]){
        cout << "impossible" << endl;
        return 0;
    }
}
cout << "possible" << endl;
rep(i,h){
    cout << ans[i] << endl;
}
return 0;
}
