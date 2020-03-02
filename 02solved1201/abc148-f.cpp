#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , u , v ;
cin >> n >> u >> v ;
u--;
v--;
vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
}
vector<ll> distt(n,-1);
vector<ll> dista(n,-1);
queue<ll> q;
distt[u]=0;
q.push(u);
while(!q.empty()){
  auto p=q.front();
  q.pop();
  for(auto r:g[p]){
    if(distt[r]!=-1)continue;
    distt[r]=distt[p]+1;
    q.push(r);
  }
}
dista[v]=0;
q.push(v);
while(!q.empty()){
  auto p=q.front();
  q.pop();
  for(auto r:g[p]){
    if(dista[r]!=-1)continue;
    dista[r]=dista[p]+1;
    q.push(r);
  }
}
rep(i,n){
  if(distt[i]<dista[i]){
    ans=max(ans,dista[i]-1);
  }
}

cout << ans << endl;
return 0;
}