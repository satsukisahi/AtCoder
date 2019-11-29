#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n,m;
cin >> n >> m ;
vector<vector<ll>> g(n);
vector<vector<ll>> gr(n);
rep(i, m)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].push_back(b-1);
    gr[b-1].push_back(a-1);
}
ll mindist=INF;
ll str=-1;
rep(i,n){
  ll dist[n]={};
  queue<ll> q;
  q.push(i);
  dist[i]=1;
  while(!q.empty()){
    ll p=q.front();q.pop();
    rep(j,g[p].size()){
      if(dist[g[p][j]]==0){
        dist[g[p][j]]=dist[p]+1;
        q.push(g[p][j]);
      }
      if(dist[g[p][j]]==1&&mindist>=dist[p]){
        mindist=dist[p];
        str=i;
      }
    }
  }
}
if(str==-1){
  cout << -1 << endl;
  return 0;
}
ll dist[n]={};
queue<ll> q;
q.push(str);
dist[str]=1;
while(!q.empty()){
  ll p=q.front();q.pop();
  rep(j,g[p].size()){
    if(dist[g[p][j]]==0){
      dist[g[p][j]]=dist[p]+1;
      q.push(g[p][j]);
    }
  }
}
ll now=str;
cout << mindist << endl;
vector<ll> ans;
set<ll> s;
rep(i,mindist){
  ll num=0;
  rep(j,gr[now].size()){
    if(dist[gr[now][j]]==mindist-i){
      num++;
      ans.push_back(gr[now][j]) ;
      s.insert(gr[now][j]);
      now=gr[now][j];
      break;
    }
  }
  assert(num==1);
}

rep(i,ans.size()){
  ll num=0;
  rep(j,g[ans[i]].size()){
    if(s.find(g[ans[i]][j])!=s.end())num++;
  }
  //assert(num==1);
}
for(auto a:ans)cout << a+1 << endl;

return 0;
}