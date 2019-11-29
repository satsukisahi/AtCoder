#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = -2;

int main()
{
ll n ;
cin >> n ;
string s[n];
rep(i,n){
  cin >> s[i];
}
vector<vector<ll>> g(n);
rep(i,n)rep(j,n)if(s[i][j]=='1')g[i].push_back(j);
rep(i,n){
  queue<ll> q;
  q.push(i);
  vector<ll> dist(n,-1);
  dist[i]=0;
  bool ok=1;
  while(!q.empty()){
    ll p=q.front(); q.pop();
    bool okk=1;
    rep(i,g[p].size()){
      if(dist[g[p][i]]==-1){dist[g[p][i]]=dist[p]+1;q.push(g[p][i]);}
      else if(!(dist[g[p][i]]==dist[p]-1 || dist[g[p][i]]==dist[p]+1)){okk=0;break;}
    }
    if(!okk){ok=0;break;}
  }
  if(ok){
    ll te=0;
    rep(i,n)te=max(te,dist[i]);
    ans=max(ans,te);
  }
}


cout << ans+1 << endl;
return 0;
}