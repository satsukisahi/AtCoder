#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
ll n ;
bool inarea(ll x,ll y){
  return x >= 0 && y >= 0 && x < n && y < n ;
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main()
{
cin >> n ;
vector<vector<ll>> v(n, vector<ll>(n,0) );
vector<vector<ll>> vv(n, vector<ll>(n,1) );
rep(i,n)rep(j,n){
  v[i][j]=min({i+1,n-i,j+1,n-j});
}
rep(i,n*n){
  ll a ;
  cin >> a ;
  a--;
  ll x=a/n,y=a%n;
  ans+=v[x][y];
  queue<pair<ll,ll>> q;
  q.push({x,y});
  v[x][y]--;
  vv[x][y]--;
  while(!q.empty()){
    auto r=q.front();
    q.pop();
    rep(j,4)if(inarea(r.first+dx[j],r.second+dy[j])&&v[r.first][r.second]+vv[r.first+dx[j]][r.second+dy[j]]<v[r.first+dx[j]][r.second+dy[j]]){
      v[r.first+dx[j]][r.second+dy[j]]=v[r.first][r.second]+vv[r.first+dx[j]][r.second+dy[j]];
      q.push({r.first+dx[j],r.second+dy[j]});
    }
  }
}
cout << ans-n*n << endl;
return 0;
}