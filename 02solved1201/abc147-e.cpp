#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
int main()
{
ll h , w ;
cin >> h >> w ;
vector<vector<ll>> v(h, vector<ll>(w,0) );
rep(i,h)rep(j,w){
  ll a ;
  cin >> a ;
  v[i][j]=a;
}
rep(i,h)rep(j,w){
  ll a ;
  cin >> a ;
  v[i][j]=abs(a-v[i][j]);
}
vector<vector<bitset<13000>>> dp(h, vector<bitset<13000>>(w) );

dp[0][0][v[0][0]]=1;
rep(i,h)rep(j,w){
  rep(k,13000){
    if(i-1>=0&&dp[i-1][j][k]){
      if(abs(k-v[i][j])<13000)dp[i][j][abs(k-v[i][j])]=1;
      if(k+v[i][j]<13000)dp[i][j][k+v[i][j]]=1;
    }
    if(j-1>=0&&dp[i][j-1][k]){
      if(abs(k-v[i][j])<13000)dp[i][j][abs(k-v[i][j])]=1;
      if(k+v[i][j]<13000)dp[i][j][k+v[i][j]]=1;
    }
  }
}
rep(i,13000){
  if(dp[h-1][w-1][i]){ans=i;break;}
}
cout << ans << endl;
return 0;
}