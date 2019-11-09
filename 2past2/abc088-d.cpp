#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
const ll INF=1<<30;
ll h,w;
ll t[50][50]={};
bool inarea(ll x,ll y){
    return x>=0&&y>=0&&x<h&&y<w;
}
ll bfs(){
    vector<vector<ll>> v(h, vector<ll>(w,INF) );
    queue<pair<int, int>> q;
    v[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        if(inarea(x+1,y)&&t[x+1][y]&&v[x][y]+1<v[x+1][y]){
            v[x+1][y]=v[x][y]+1;
            q.push({x+1,y});
        }
        if(inarea(x-1,y)&&t[x-1][y]&&v[x][y]+1<v[x-1][y]){
            v[x-1][y]=v[x][y]+1;
            q.push({x-1,y});
        }
        if(inarea(x,y+1)&&t[x][y+1]&&v[x][y]+1<v[x][y+1]){
            v[x][y+1]=v[x][y]+1;
            q.push({x,y+1});
        }
        if(inarea(x,y-1)&&t[x][y-1]&&v[x][y]+1<v[x][y-1]){
            v[x][y-1]=v[x][y]+1;
            q.push({x,y-1});
        }
    }
    return v[h - 1][w - 1];
}


int main()
{ 

cin >>h>>w; 

char maze[51][51];
ll wh=0;

rep(j,h){rep(i,w) {
    cin >> maze[j][i];
    if(maze[j][i]=='.'){t[j][i]=1;wh++;}
    else t[j][i]=0;
}}

ans=bfs();
if(ans==INF)cout << -1 << endl;
else cout << wh-ans-1 << endl;
return 0;
} 