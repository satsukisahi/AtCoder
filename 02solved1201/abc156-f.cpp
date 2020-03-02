#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll k , q ;
cin >> k >> q ;
vector<ll> d(k);
rep(i, k){
  cin >> d[i];
}
vector<vector<ll>> v(q, vector<ll>(3,0) );
rep(i,q){
  cin >> v[i][0] >> v[i][1] >> v[i][2];
  v[i][0]--;
  v[i][1]%=v[i][2];
}
rep(i,q){
  ll zero=0,sum=0,ans=0;
  rep(j,k){
    sum+=d[j]%v[i][2];
    if(d[j]%v[i][2]==0)zero++;
  }
  ans+=v[i][0]/k*(k-zero)-(v[i][1]+(v[i][0]/k)*sum)/v[i][2];
  ll st=(v[i][1]+v[i][0]/k*sum)%v[i][2];
  rep(j,(v[i][0])%k){
    if(st<(st+d[j])%v[i][2])ans++;
    st=(st+d[j])%v[i][2];
  }
  cout << ans << endl;
}
return 0;
}