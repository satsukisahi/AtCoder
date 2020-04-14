#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1LL<<50;
set<ll> s[200010];
int main()
{
ll h , w , n ;
cin >> h >> w >> n ;

//vector<vector<char>> v(h+1, vector<char>(w+1,'.') );
map<pair<ll,ll>,bool> m;
rep(i,n){
  ll x , y ;
  cin >> x >> y ;
  //v[x-1][y-1]='#';
  m[{x-1,y-1}]=1;
  s[y-1].insert(x-1);
}
//rep(i,w)v[i][w]='#';
rep(i,h)m[{i,w}]=1;
//rep(i,h){v[h][i]='#';s[i].insert(h);}
rep(i,w){m[{h,i}]=1;s[i].insert(h);}
ll x=0,y=0;
/* rep(i,h+1){
rep(j,w+1)cout << v[i][j];
cout << endl;
} */
rep(i,h){
  ans=min(ans,*upper_bound(s[y].begin(),s[y].end(),x));
  //if(v[x+1][y]=='#')break;
  if(m.find({x+1,y})!=m.end())break;
  x++;
  //if(v[x][y+1]=='.')y++;
  if(m.find({x,y+1})==m.end())y++;
}

cout << ans << endl;
return 0;
}