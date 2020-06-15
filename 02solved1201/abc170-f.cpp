#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
ll h , w , k ;
bool inarea(ll x,ll y){
  return x >= 0 && y >= 0 && x < h && y < w ;
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main()
{
cin >> h >> w >> k ;
ll xs , xg , ys , yg ;
cin >> xs >> ys >> xg >> yg ;
xs--;xg--;ys--;yg--;
vector<vector<ll>> v(h, vector<ll>(w,0) );
vector<vector<ll>> d(h, vector<ll>(w,10000000) );
rep(i,h)rep(j,w){
  char a ;
  cin >> a ;
  if(a=='@')v[i][j]=1;
}
queue<pair<ll,ll>> q;
q.push({xs,ys});
d[xs][ys]=0;
while(!q.empty()){
  auto p=q.front();
  q.pop();
  rep(l,4){
    rep(i,k){
      if(!inarea(p.first+dx[l]*(i+1),p.second+dy[l]*(i+1)))break;
      if(v[p.first+dx[l]*(i+1)][p.second+dy[l]*(i+1)])break;
      if(d[p.first+dx[l]*(i+1)][p.second+dy[l]*(i+1)]<=d[p.first][p.second])break;
      if(d[p.first+dx[l]*(i+1)][p.second+dy[l]*(i+1)]>d[p.first][p.second]+1){
        d[p.first+dx[l]*(i+1)][p.second+dy[l]*(i+1)]=d[p.first][p.second]+1;
        q.push({p.first+dx[l]*(i+1),p.second+dy[l]*(i+1)});
      }
    }
  }
}
cout << (d[xg][yg]==10000000?-1:d[xg][yg]) << endl;
return 0;
}
