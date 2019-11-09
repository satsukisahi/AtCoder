#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807
void warshallfloyd(vector<vector<ll>> &d)
{
  for (int k = 0; k < d.size(); k++)
    for (int i = 0; i < d.size(); i++)
      for (int j = 0; j < d.size(); j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
ll n ,mx=-1;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> b(n);
rep(i, n){
  cin >> b[i];
}
rep(i,n){
  if(!(a[i]==b[i]||a[i]>b[i]*2)){
    cout << -1 << endl;
    return 0;
  }
  if(a[i]!=b[i])mx=max(mx,a[i]);
}
if(mx==-1){
  cout << 0 << endl;
  return 0;
}
vector<bool> an(mx+1,1);
an[0]=0;
an[mx]=0;
for (ll i = mx-1; i > 0; i--)
{
  an[i]=0;
  vector<vector<ll>> d(mx+1, vector<ll>(mx+1, INF));
  rep(j, mx+1)d[j][j] = 0;
  rep(k,mx)rep(l,mx){
    if(an[l+1])d[k+1][(k+1)%(l+1)]=0;
  }
  warshallfloyd(d);
  rep(k,n){
    if(d[a[k]][b[k]]!=0)an[i]=1;
  }
}
rep(i,an.size()){
  if(an[i])ans+=1LL<<i;
}
cout << ans << endl;
return 0;
}
