#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807
int main()
{
ll h , w ;
cin >> h >> w ;
vector<string> s(h);
rep(i, h){
  cin >> s[i];
}
rep(i,w-1){
vector<vector<ll>> v(h, vector<ll>(h,0) );
vector<vector<ll>> vv(h, vector<ll>(h,INF) );
vv[0][0]=0;
ll c=0;
rep(j,h){
  if(s[j][i]==s[j][i+1])c++;
  v[h-1-j][h-1-j]=c;
}
rep(l,h-1){
  c=0;
  rep(j,h-l-1){
    if(s[j][i]==s[j+l+1][i+1])c++;
    v[h-1-j][h-1-j-l-1]=c;
  }
  c=0;
  rep(j,h-l-1){
    if(s[j+l+1][i]==s[j][i+1])c++;
    v[h-1-j-l-1][h-1-j]=c;
  }
}
vv[0][0]=v[0][0];
rep(i,h-1){
  rep(j,h-1){
    vv[i][j+1]=min(vv[i][j+1],vv[i][j]+v[i][j+1]);
    vv[i+1][j]=min(vv[i+1][j],vv[i][j]+v[i+1][j]);
  }
}
ll t=INF;
rep(i,h)t=min(t,vv[i][h-1]);
rep(i,h)t=min(t,vv[h-1][i]);
ans+=t;
}

cout << ans << endl;
return 0;
}