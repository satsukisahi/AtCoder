#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
string s , t ;
cin >> s >> t ;
vector<vector<ll>> v(s.size(), vector<ll>(26,INF) );
vector<vector<ll>> ta(26, vector<ll>() );
rep(i,s.size()){
  ta[s[i]-'a'].push_back(i);
}
rep(i,26){
  if(ta[i].size()!=0)ta[i].push_back(ta[i][0]+s.size());
}
rep(i,s.size()){
  rep(j,26){
    auto itr = upper_bound(ta[j].begin(), ta[j].end(), i);
    if(itr!=ta[j].end())v[i][j]=*itr-i;
  }
}
ll now=0;
rep(i,t.size()){
  if(!(i==0&&t[0]==s[0])){
  ans+=v[now][t[i]-'a'];
  now+=v[now][t[i]-'a'];
  now%=s.size();
  if(ans>=INF){
    cout << -1 << endl;
    return 0;
  }
  }
}

cout << ans+1 << endl;
return 0;
}
