#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll d , l , n ;
cin >> d >> l >> n ;
vector<ll> c(d);
rep(i, d){
  cin >> c[i];
}
vector<ll> ans(n,0);
vector<vector<ll>> v(100001,vector<ll>(0));
rep(i,d)v[c[i]-1].push_back(i);
vector<vector<ll>> nx(35, vector<ll>(d,0) );
vector<vector<ll>> dub(35, vector<ll>(d,0) );
rep(i,v.size())rep(j,v[i].size()){
  dub[0][v[i][j]]=((v[i][((j<v[i].size()-1)?j+1:0)]-v[i][j]+d-1)%d)/l +1;
  nx[0][v[i][j]]=v[i][((j<v[i].size()-1)?j+1:0)];
}
rep(i,34){
  rep(j,d){
    nx[i+1][j]=nx[i][nx[i][j]];
  }
}
rep(i,34){
  rep(j,d){
    dub[i+1][j]=dub[i][j]+dub[i][nx[i][j]];
  }
}
rep(i,v.size())if(v[i].size()>0)v[i].push_back(v[i][0]+d);
rep(i,n){
  ll k , f , t ;
  cin >> k >> f >> t ;
  k--;f--;  
  if(v[k].size()==0)continue;
  ll tr=*lower_bound(v[k].begin(),v[k].end(),f);
  t-=(tr-f +l-1)/l;
  if(t<=0)continue;
  t--;
  ll te=1,itr=tr%d;
  rep(i,35){
    if(t>=dub[34-i][itr]){
      te+=1LL<<(34-i);
      t-=dub[34-i][itr];
      itr=nx[34-i][itr];
    }
  }
  ans[i]=te;
}
for(auto an:ans)cout << an << endl;
return 0;
}