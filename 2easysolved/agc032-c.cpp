#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , m ;
cin >> n >> m ;
vector<vector<ll>> g(n);
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
}
rep(i,n){
  if(g[i].size()%2!=0){
    cout << "No" << endl;
    return 0;
  }
}
ll f=0;
rep(i,n){
  if(g[i].size()>=6){
    cout << "Yes" << endl;
    return 0;
  }
  if(g[i].size()==4)f++;
}
if(f<2){
  cout << "No" << endl;
  return 0;
}
if(f>2){
  cout << "Yes" << endl;
  return 0;
}
vector<ll> t;
ll v;
rep(i,n){
  if(g[i].size()==4)v=i;
}
vector<ll> see(n);
see[v]=1;
queue<ll> q;
rep(i,4){
  q.push(g[v][i]);
}
while(!q.empty()){
  ll p=q.front();
  q.pop();
  if(g[p].size()==4){
    t.push_back(p);
    continue;
  }
  see[p]=1;
  rep(i,2){
    if(see[g[p][i]]==0)q.push(g[p][i]);
  }
}
if(t.size()==2){
  cout << "Yes" << endl;
  return 0;
}
else{
  cout << "No" << endl;
  return 0;
}
}