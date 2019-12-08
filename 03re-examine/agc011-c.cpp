#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
int bfs(vector<vector<ll>> &g , ll st,vector<ll> &see,vector<ll> &dist){
  ll rt=1;
  queue<ll> q;
  see[st]=1;
  q.push(st);
  while(!q.empty()){
    auto p=q.front();
    see[p]=1;
    q.pop();
    for(auto r:g[p]){
      if(see[r]!=0){
        if(dist[r]%2==dist[p]%2)rt=2;
        continue;
      }
      dist[r]=dist[p]+1;
      q.push(r);
    }
  }
  return rt;
}
int main()
{
ll n , m ;
cin >> n >> m ;
vector<vector<ll>> g(n);
vector<ll> see(n);
vector<ll> dist(n);
vector<ll> an(3);
set<ll> s;
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  s.insert(a-1);
  s.insert(b-1);
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
}
an[0]=n-s.size();
rep(i,n){
  if(see[i]||s.find(i)==s.end())continue;
  an[bfs(g,i,see,dist)]++;
}
cout << an[0]*(2*n-an[0])+2*an[1]*an[1]+2*an[1]*an[2]+an[2]*an[2] << endl;
return 0;
}