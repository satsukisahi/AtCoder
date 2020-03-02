#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


int main()
{
ll n ;
cin >> n ;
if(n==2){
  cout << -1 << endl;
  return 0;
}
if(n==3){
  cout << "aa." << endl;
  cout << "..a" << endl;
  cout << "..a" << endl;
  return 0;
}
vector<vector<ll>> v(n, vector<ll>(n,0) );
ll b=0;
ll c;
while(1){
  c=n-b*4;
  if(c>=4&&c<=7)break;
  v[b*4][b*4]=1;
  v[b*4][b*4+1]=1;
  v[b*4+1][b*4]=2;
  v[b*4+1][b*4+1]=2;
  v[b*4+2][b*4]=3;
  v[b*4+3][b*4]=3;
  v[b*4+2][b*4+1]=4;
  v[b*4+3][b*4+1]=4;
  v[b*4][b*4+2]=5;
  v[b*4+1][b*4+2]=5;
  v[b*4][b*4+3]=8;
  v[b*4+1][b*4+3]=8;
  v[b*4+2][b*4+2]=6;
  v[b*4+2][b*4+3]=6;
  v[b*4+3][b*4+2]=7;
  v[b*4+3][b*4+3]=7;
  b+=1;
}
rep(i,4*b){
  rep(j,n){
    if(v[i][j]==0)cout << '.' ;
    else cout << char('a'+v[i][j]) ;
  }
cout << endl ;
}
string k[4][7]={{"aabc","ddbc","bcaa","bcdd"},{"aabba","bcc.a","b..cb","a..cb","abbaa"},{"aabc..","ddbc..","..aabc","..ddbc","bc..aa","bc..dd"},{"aabbcc.","dd.dd.a","..d..da","..d..db","dd.dd.b","..d..dc","..d..dc"}};
rep(i,c){
  rep(j,4*b)cout << '.' ;
  cout << k[c-4][i] << endl;
  
}
return 0;
}