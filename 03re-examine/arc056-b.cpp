#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n, m,s;
cin >> n >> m>>s;
s--;
vector<vector<ll>> g(n);
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
}
vector<bool> see(n);
vector<bool> ans(n);
vector<ll> mi(n);
priority_queue<pair<ll,ll>> q;
see[s]=1;
mi[s]=s;
ans[s]=1;
q.push({s,s});
while(!q.empty()){
  auto p=q.top();
  q.pop();
  for(auto r:g[p.second]){
    if(see[r])continue;
    see[r]=1;
    if(r<p.first)ans[r]=1;
    q.push({min(r,p.first),r});
  }
}
rep(i,n)if(ans[i])cout << i+1 << endl;
return 0;
}