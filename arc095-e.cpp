#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll h , w ;
cin >> h >> w ;
string s[h];
rep(i,h){
  cin >> s[i];
}
map<string,ll> m;
rep(i,h){
  string te=s[i];
  sort(te.begin(),te.end());
  m[te]++;
}
map<string,ll> mm;
rep(i,w){
  string te;
  rep(j,h)te+=s[j][i];
  sort(te.begin(),te.end());
  mm[te]++;
}
ll odd=0;
for (auto i = m.begin(); i != m.end(); ++i) {
  if(i->second%2)odd++;
}
if(( h%2==1 && odd>1 )||( h%2==0 && odd>0) ){
  cout << "NO" << endl;
  return 0;
}
odd=0;
for (auto i = mm.begin(); i != mm.end(); ++i) {
  if(i->second%2)odd++;
}
if(( w%2==1 && odd>1 )||( w%2==0 && odd>0) ){
  cout << "NO" << endl;
  return 0;
}
  cout << "YES" << endl;
  return 0;

}