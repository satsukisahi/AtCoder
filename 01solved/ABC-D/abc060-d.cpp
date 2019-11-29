#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,w;
cin >> n>>w;
vector<vector<ll>> v(4);
ll w1,v1;
cin >> w1 >> v1 ;
v[0].push_back(v1);
rep(i, n-1){
    ll ww,vv;
    cin >> ww >> vv ;
    v[ww-w1].push_back(vv);
}
rep(i,4){
    sort(v[i].rbegin(),v[i].rend());
}
vector<vector<ll>> vvv(4);
rep(i,4)vvv[i].push_back(0);
rep(i,4){
    rep(j,v[i].size()){
        vvv[i].push_back(vvv[i][j]+v[i][j]);
    }
}
rep(i,vvv[0].size())rep(j,vvv[1].size())rep(k,vvv[2].size())rep(l,vvv[3].size()){
    if(i*w1+j*(w1+1)+k*(w1+2)+l*(w1+3)>w)continue;
    ans=max(ans,vvv[0][i]+vvv[1][j]+vvv[2][k]+vvv[3][l]);
}

cout << ans << endl;
return 0;
}
