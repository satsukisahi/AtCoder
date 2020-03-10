#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
int main()
{
ll n;
cin >> n ;
vector<vector<edge>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b ;
  ll c=0;
  g[a - 1].emplace_back(b - 1, c);
  g[b - 1].emplace_back(a - 1, c); //無向辺
}
ll a=1,b=2,c=3;
ll ev=1,od=0;
vector<ll> par(n);
vector<ll> res(n);
vector<bool> see(n);
queue<ll> q;
par[0]=-1;
see[0]=1;
res[0]=0;
q.push(0);
while(!q.empty()){
  auto p=q.front();
  see[p]=1;
  q.pop();
  for(auto r:g[p]){
    if(see[r.to]!=0)continue;
    par[r.to]=p;
    res[r.to]=res[p]+1;
    if(res[r.to]%2)od++;
    else ev++;
    q.push(r.to);
  }
}
vector<ll> ans(n,-1);
if(od>n/3&&ev>n/3){
  rep(i,n){
    if(res[i]%2){
      if(a>n) {ans[i]=c;c+=3;}
      else{ans[i]=a;a+=3;}
    }
    else{
      if(b>n) {ans[i]=c;c+=3;}
      else{ans[i]=b;b+=3;}
    }
  }
}
else if(od>n/3)
{
  rep(i,n){
    if(res[i]%2==0){ans[i]=c;c+=3;}
  }
  rep(i,n){
    if(res[i]%2==1&&c<=n){ans[i]=c;c+=3;}
    else if(res[i]%2==1&&a<=n){ans[i]=a;a+=3;}
    else if(res[i]%2==1){ans[i]=b;b+=3;}
  }
}
else
{
  rep(i,n){
    if(res[i]%2==1){ans[i]=c;c+=3;}
  }
  rep(i,n){
    if(res[i]%2==0&&c<=n){ans[i]=c;c+=3;}
    else if(res[i]%2==0&&a<=n){ans[i]=a;a+=3;}
    else if(res[i]%2==0){ans[i]=b;b+=3;}
  }
}

for(auto r : ans)cout << r << ' ';
cout << endl;
return 0;
}
