#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll solve(ll n,ll m,vector<vector<ll>> &v,vector<ll> &itr,vector<vector<ll>> &s){
  bool nop[m]={};
  ll ans=n;
  while(1){
    bool ok=1;
    vector<ll> te;
    rep(l,m){
      if(s[l].size()>ans){
        for(auto w:s[l])te.push_back(w);
        s[l].clear();
        nop[l]=1;
      }
    }
    for(auto w:te){
      ok=0;
      while(1){
        itr[w]++;
        if(itr[w]==m)return ans+1;
        if(nop[v[w][itr[w]]]==0)break;
      }
      s[v[w][itr[w]]].push_back(w);
    }
    if(ok)ans--;
  }
  return -1;
}

int main()
{
ll n , m ;
cin >> n >> m ;
vector<vector<ll>> v(n, vector<ll>(m,0) );
rep(i,n)rep(j,m){
  cin >> v[i][j];
  v[i][j]--;
}

vector<vector<ll>> s(m);
vector<ll> itr(n);
rep(j,n){
  s[v[j][0]].push_back(j);
}
cout << solve(n,m,v,itr,s) << endl;
return 0;
}