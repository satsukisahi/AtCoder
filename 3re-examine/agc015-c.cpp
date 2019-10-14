#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , m , q ;
cin >> n >> m >> q ;
string s[n];
rep(i,n){
  cin >> s[i];
}
vector<vector<ll>> cnt(n+1, vector<ll>(m+1,0) );
rep(i,n)rep(j,m){
  cnt[i+1][j+1]=(s[i][j]=='1' ? 1 : 0)+cnt[i][j+1]+cnt[i+1][j]-cnt[i][j];
}
vector<vector<ll>> ed(n+1, vector<ll>(m+1,0) );
rep(i,n)rep(j,m){
  ed[i+1][j+1]=(i+1<n&&s[i][j]=='1'&&s[i+1][j]=='1' ? 1 : 0)+ed[i][j+1]+ed[i+1][j]-ed[i][j];
}
vector<vector<ll>> ed1(n+1, vector<ll>(m+1,0) );
rep(i,n)rep(j,m){
  ed1[i+1][j+1]=(j+1<m&&s[i][j]=='1'&&s[i][j+1]=='1' ? 1 : 0)+ed1[i][j+1]+ed1[i+1][j]-ed1[i][j];
}
rep(i,q){
  ll x1 , y1 , x2 , y2 ;
  cin >> x1 >> y1 >> x2 >> y2 ;
  cout << cnt[x2][y2]-cnt[x1-1][y2]-cnt[x2][y1-1]+cnt[x1-1][y1-1]-(ed[x2-1][y2]-ed[x1-1][y2]-ed[x2-1][y1-1]+ed[x1-1][y1-1])-(ed1[x2][y2-1]-ed1[x1-1][y2-1]-ed1[x2][y1-1]+ed1[x1-1][y1-1]) << endl;
}
return 0;
}