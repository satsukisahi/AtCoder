#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll x , k ;
cin >> x >> k ;
vector<ll> r(k+1);
rep(i,k){
  cin >> r[i+1];
}
ll q ;
cin >> q ;
ll ans[q] = {};
pair<ll,ll> qq[q];
rep(i,q){
  ll t , a ;
  cin >> t >> a ;
  qq[i]={t,a};
}
ll itr=0;
ll mx=x,mi=0,c=0;
bool isdec=1;
rep(i,q){
  while(itr!=k && r[itr+1]<qq[i].first ){
    //更新
    if(isdec){
      c-=r[itr+1]-r[itr];
      if(-c>mi)mi=-c;
      if(mx<mi)mx=mi;
    }
    else{
      c+=r[itr+1]-r[itr];
      if(mx+c>x)mx=x-c;
      if(mx<mi)mi=mx;
    }
    isdec=!isdec;
    itr++;
  }
  ll te;
  if(qq[i].second>mx)te=mx+c;
  else if(qq[i].second<mi)te=mi+c;
  else te=qq[i].second+c;
  if(isdec)te-=qq[i].first-r[itr];
  else te+=qq[i].first-r[itr];
  if(te>x)te=x;
  else if(te<0)te=0;
  ans[i]=te;
}
rep(i,q)cout << ans[i] << endl;
return 0;
}