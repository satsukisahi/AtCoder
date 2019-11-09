#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll y[2000][2000]={};
ll t[2000][2000]={};

int main()
{
ll h,w;
cin >> h>>w;
string ta[h] = {};
rep(i, h){
    cin >> ta[i];
}
rep(i, h)
{
    ll co = 0;
    ll see = 0;
    rep(j, w)
    {
        
        if (ta[i][j] == '.')
            co++;
        if (ta[i][j] == '#'){
            rep(k,co){
                y[i][k+see]=co;
            }
            co=0;
            see=j+1;
        }
        if(j==w-1){
            rep(k,co){
            y[i][k+see]=co;
            }
        }
    }
}
rep(i, w)
{
    ll co = 0;
    ll see = 0;
    rep(j, h)
    {
        
        if (ta[j][i] == '.')
            co++;
        if (ta[j][i] == '#'){
            rep(k,co){
                t[k+see][i]=co;
            }
            co=0;
            see=j+1;
        }
        if(j==h-1){
            rep(k,co){
            t[k+see][i]=co;
            }
        }
    }
}

//2次元配列の中身を見る

/* for (int i = 0; i < h; ++i){
for (int j = 0; j < w; ++j) {
    cout << t[i][j] << " ";
}cout  << endl;}
 */
rep(i,h)rep(j,w){
    ans=max(ans,t[i][j]+y[i][j]-1);
}

cout << ans << endl;
return 0;
}