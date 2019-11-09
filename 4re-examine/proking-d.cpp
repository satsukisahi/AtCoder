//全国統一プログラミング王予選
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , m ,root;
cin >> n >> m ;
vector<vector<ll>> g(n);
set<ll> s;
vector<ll> f(n);
rep(i,n-1+m)
{
  ll a, b;
  cin >> a >> b;
  s.insert(b-1);
  f[b-1]++;
  g[a - 1].push_back(b - 1);
}
rep(i,n){
  if(s.find(i)==s.end())root=i;
}
vector<ll> par(n);
par[root]=-1;
queue<ll> q;
q.push(root);
while(!q.empty()){
  ll p=q.front();
  q.pop();
  for(auto r:g[p]){
    par[r]=p;
    f[r]--;
    if(f[r]==0)q.push(r);
  }
}
for(auto an:par)cout << an+1 << endl;
return 0;
}