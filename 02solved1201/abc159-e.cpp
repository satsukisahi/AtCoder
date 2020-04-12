#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 10000000;

int main()
{
ll h , w , k ;
cin >> h >> w >> k ;
vector<vector<ll>> v(h, vector<ll>(w,0) );
rep(i,h*w){
  char a ;
  cin >> a ;
  v[i/w][i%w]=a-'0';
}
rep(i,1LL<<(h-1)){
  ll an=0;
  ll ta=0;
  an+=__builtin_popcountll(i);
  vector<ll> a(an+1,0);

  rep(j,w){
    vector<ll> b(an+1,0);
    ll itr=0;

    rep(l,h){
      b[itr]+=v[l][j];
      if(i>>l&1LL)itr++;
    }

    bool ok=1;

    rep(l,an+1){
      if(a[l]+b[l]<=k)a[l]+=b[l];
      else ok=0;
    }

    if(ok==0){
      ta++;
      rep(l,an+1)a[l]=b[l];
    }
  }
  bool ook=1;
  for(auto r:a)if(r>k)ook=0;
  if(ook)ans=min(ans,an+ta);
}
cout << ans << endl;
return 0;
}