#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;
char a[1010][1010];
ll b[1010][1010];
ll h,w;
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};
bool in(ll x,ll y){
    return (x>=0&&y>=0&&x<w&&y<h);
}

int main()
{ 

cin >> h>>w; 
queue<pair<int, int>> q;
rep(j,h)rep(i,w) {
    b[j][i]=INF;
    cin >> a[j][i];
    if(a[j][i]=='#'){
        q.push({i,j});
        b[j][i]=0;
    }
}
while(!q.empty()){
    pair<int, int> p = q.front();
    int x = p.first;
    int y = p.second;
    q.pop();
    rep(i,4){
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        if(in(nx,ny)&&b[ny][nx]==INF){
            b[ny][nx]=b[y][x]+1;
            q.push({nx,ny});
        }
    }
}
rep(j,h)rep(i,w) {
    ans=max(ans,b[j][i]);
}
cout << ans << endl;
return 0;
} 