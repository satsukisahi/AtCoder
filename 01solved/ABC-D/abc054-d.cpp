#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;
ll t[401][401] = {};

int main()
{
ll n,ma,mb;
cin >> n>>ma>>mb;

rep(i,401)rep(j,401){
    t[i][j]=INF;
}
t[0][0]=0;
tuple<ll, ll, ll> data[n];
rep(i,n){
    ll a,b,c;
    cin >> a>>b>>c;
    data[i] = make_tuple(a, b, c);
}
rep(i,n){
    ll x,y,z;
    tie(x, y, z) = data[i];
    rep(j,401)rep(k,401){
        if(t[400-j][400-k]!=INF){
            t[400-j+y][400-k+x]=min(t[400-j+y][400-k+x],t[400-j][400-k]+z);
        }
    }
}
ll ca=ma,cb=mb;
bool ch=0;
while(ca<401&&cb<401){
    if(t[cb][ca]!=INF){
        ch=1;
        ans=min(ans,t[cb][ca]);
    }
    ca+=ma;
    cb+=mb;
}
if(ch)cout << ans << endl;
else cout << "-1" << endl;
return 0;
}