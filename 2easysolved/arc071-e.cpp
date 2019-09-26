#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
string s , t ;
cin >> s >> t ;
ll q ;
cin >> q ;
vector<ll> sa(1),sb(1),ta(1),tb(1);
rep(i,s.size()){
  if(s[i]=='A')sa.push_back(sa.back()+1);
  else sa.push_back(sa.back());
  if(s[i]=='B')sb.push_back(sb.back()+1);
  else sb.push_back(sb.back());
  if(t[i]=='A')ta.push_back(ta.back()+1);
  else ta.push_back(ta.back());
  if(t[i]=='B')tb.push_back(tb.back()+1);
  else tb.push_back(tb.back());
}
vector<bool> ans;
rep(i,q){
  ll a , b , c , d ;
  cin >> a >> b >> c >> d ;
  ll numa=sa[b]-sa[a-1];
  ll numb=sb[b]-sb[a-1];
  ll numaa=ta[d]-ta[c-1];
  ll numbb=tb[d]-tb[c-1];
  if((numa+numb*2)%3==(numaa+numbb*2)%3) ans.push_back(true);
  else ans.push_back(false);
}
for(auto an:ans){
  if(an) cout << "YES" << endl;
  else cout << "NO" << endl;
}

return 0;
}