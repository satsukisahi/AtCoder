#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n ;
cin >> n ;
vector<ll> x(n+1);
/* rep(i, n){
  cin >> x[i];
} */
for(int i=0;i<n;++i) scanf("%d",&x[i]);
x[n]=INF;
ll l , q ;
cin >> l >> q ;
vector<vector<ll>> dub(20, vector<ll>(n,0) );
ll st=0,en=1;
rep(i,n-1){
  while(x[en+1]-x[i]<=l)en++;
  dub[0][i]=en;
}
dub[0][n-1]=-1;
ll dep;
rep(i,19){
  rep(j,n){
    if(dub[i][j]==-1)dub[i+1][j]=-1;
    else dub[i+1][j]=dub[i][dub[i][j]];
  }
  if(dub[i+1][0]==-1){
    dep=i;
    break;
  }
}
rep(ii,q){
  ll a , b ;
  cin >> a >> b ;
  a--;b--;
  if(a>b)swap(a,b);
  ll ans=0;
  for (ll i = dep; i >= 0; i--)
  {
    if(0<x[dub[i][a]] && x[dub[i][a]] <x[b]){
      ans+=1LL<<i;
      a=dub[i][a];
    }
  }
  cout << ans+1 << endl;

}
return 0;
}