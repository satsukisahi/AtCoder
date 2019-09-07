#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll n ;
cin >> n ;
vector<pair<ll,bool>> v;
map<pair<ll,bool>,ll> m;
rep(i,2*n){
  ll a ;
  char b ;
  cin >> b >> a ;
  if(b=='W'){v.emplace_back(a-1,0);m[{a-1,0}]=i;}
  else {v.emplace_back(a-1,1);m[{a-1,1}]=i;}
}
ll bl[2*n][n+1]={};
ll wh[2*n][n+1]={};
rep(i,n){
  ll b=0,w=0;
  rep(j,2*n){
    bl[j][i]=b;
    wh[j][i]=w;
    if(v[j].second&&v[j].first>=i)b++;
    if(!v[j].second&&v[j].first>=i)w++;
  }
}
ll dp[n+1][n+1];//w,b
rep(i,n+1)rep(j,n+1)dp[i][j]=INF;
dp[0][0]=0;
rep(i,n+1)rep(j,n+1){
  if(i!=n)dp[i+1][j]=min(dp[i+1][j],dp[i][j]+wh[m[{i,0}]][i]+bl[m[{i,0}]][j]);
  if(j!=n)dp[i][j+1]=min(dp[i][j+1],dp[i][j]+wh[m[{j,1}]][i]+bl[m[{j,1}]][j]);
}
cout << dp[n][n] << endl;
return 0;
}
