#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans=0;

const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};
struct point
{
    ll x,y,cost;
};
bool cmp(const point &a, const point &b)
{
    return a.cost < b.cost;
}
int main()
{
ios::sync_with_stdio(false);
ll h,w;
cin >> h>>w;
ll t[h][w] = {};
vector<point> v;
rep(i, h)rep(j,w){
    cin >> t[i][j];
    point p;
    p.x=j;p.y=i;p.cost=t[i][j];
    v.push_back(p);
}
sort(v.begin(),v.end(),cmp);
vector<vector<ll>> an(h, vector<ll>(w,1) );
rep(i,h*w){
    point p;
    p=v[i];
    rep(j,4){
        if(p.x+dx[j]>=0&&p.x+dx[j]<w&&p.y+dy[j]>=0&&p.y+dy[j]<h&&t[p.y][p.x]<t[p.y+dy[j]][p.x+dx[j]]){
            an[p.y+dy[j]][p.x+dx[j]]+=an[p.y][p.x];
            an[p.y+dy[j]][p.x+dx[j]]%=mo;
        }
    }
}
rep(i,h)rep(j,w){
    ans+=an[i][j];
    ans%=mo;
}
cout << ans << endl;
return 0;
}
