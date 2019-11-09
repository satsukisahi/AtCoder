#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n,m;
cin >> n >> m ;
set<ll> g[n];
rep(i, m)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].insert(b-1);
    g[b-1].insert(a-1);
}
vector<vector<ll>> gg(n);
rep(i,n)rep(j,n){
  if(i==j)continue;
  if(g[i].find(j)==g[i].end())gg[i].push_back(j);
}
bool see[n]={};
bitset<800> dp;
dp[0]=1;
vector<ll> dist(n);
rep(i,n){
  if(!see[i]){
    ll odd=0,even=1;
    queue<ll> s;
    s.push(i);
    see[i]=1;
    while(s.size()!=0){
      ll now=s.front();
      s.pop();
      for (auto p : gg[now])
      {
        if (see[p] && (dist[p]==dist[now]-1 || dist[p]==dist[now]+1))
            continue;
        else if(see[p]){
          cout << -1 << endl;
          return 0;
        }
        see[p]=1;
        dist[p]=dist[now]+1;
        if(dist[p]%2)odd++;
        else even++;
        s.push(p);
      }
    }
    dp=(dp << odd)|(dp<<even);

  }
}
rep(i,n){
  if(dp[i])ans=min(ans,i*(i-1)/2 +(n-i)*(n-i-1)/2);
}
cout << ans << endl;
return 0;
}