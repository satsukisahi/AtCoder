#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;
int main()
{
ll n ;
cin >> n ;
vector<vector<ll>> v(n, vector<ll>(3,0) );
rep(i,n)cin >> v[i][0];
rep(i,n)cin >> v[i][1];
rep(i,n) v[i][2]=i;
rep(i,1LL<<n){
  if(__builtin_popcountll(i)!=(n+1)/2)continue;
  vector<ll> a,b;
  rep(j,n){
    if((i>>j &1LL) && j%2)a.push_back(v[j][1]);
    else if((i>>j &1LL) && j%2==0)a.push_back(v[j][0]);
    else if(j%2)b.push_back(v[j][0]);
    else b.push_back(v[j][1]);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  bool ok=1;
  rep(i,n-1){
    if(i%2 && b[i/2]>a[i/2 +1]){ok=0;break;}
    else if(a[i/2]>b[i/2]){ok=0;break;}
  }
  if(!ok)continue;
  ll an=0;
  vector<ll> nw;
  rep(j,n)nw.push_back(((i>>j &1LL)^(j%2))?v[j][0]:v[j][1]);
  vector<ll> see(n);
  rep(j,n){
    ll tar=(j%2?b[j/2]:a[j/2]);
    ll cnt=0;
    rep(k,n){
      if(j%2==0 && (i>>k &1LL)==1 && tar==nw[k] && see[k]==0){
        an+=k-cnt;
        see[k]=1;
        break;
      }
      else if(j%2 && (i>>k &1LL)==0 && tar==nw[k] && see[k]==0){
        an+=k-cnt;
        see[k]=1;
        break;
      }
      if(see[k]==1)cnt++;
    }
  }
  ans=min(ans,an);
}
if(ans==INF)ans=-1;
cout << ans << endl;
return 0;
}