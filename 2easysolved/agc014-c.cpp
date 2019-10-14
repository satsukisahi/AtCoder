#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 9999999999;
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
ll h , w , k ;
bool inarea(ll x,ll y){
  return x >= 0 && y >= 0 && x < h && y < w ;
}

int main()
{
cin >> h >> w >> k ;
string s[h];
rep(i,h){
  cin >>s[i];
}
vector<pair<ll,ll>> v;
ll dist[h][w]={};
queue<pair<ll,ll>> q;
rep(i,h)rep(j,w){
  if(s[i][j]=='S'){q.push({i,j});
  dist[i][j]=1;
  v.emplace_back(i,j);}
}
while(!q.empty()){
  auto p=q.front();
  q.pop();
  if(p.first==0 || p.first==h-1 || p.second==0 || p.second==w-1){
    cout << 1 << endl;
    return 0;
  }
  rep(i,4){
    ll x=p.first+dx[i];
    ll y=p.second+dy[i];
    if(inarea(x,y) && dist[x][y]==0 && dist[p.first][p.second]<=k && s[x][y]=='.'){
      dist[x][y]=dist[p.first][p.second]+1;
      q.push({x,y});
      v.push_back({x,y});
    }
  }
}
for(auto a:v){
  ans=min(ans,(a.first+k-1)/k);
  ans=min(ans,(h-1-a.first+k-1)/k);
  ans=min(ans,(a.second+k-1)/k);
  ans=min(ans,(w-1-a.second+k-1)/k);
}
cout << ans+1 << endl;
return 0;
}