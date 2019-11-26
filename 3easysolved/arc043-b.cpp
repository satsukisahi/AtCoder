#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;

int main()
{
ll n ;
cin >> n ;
vector<ll> d(n);
rep(i, n){
  cin >> d[i];
}
sort(d.begin(),d.end());

vector<vector<ll>> v(4, vector<ll>(n,0) );
rep(i,n)v[0][i]=1;
rep(j,3){
  rep(i,n){
    auto itr = lower_bound(d.begin(), d.end(), d[i]*2);
    if(itr==d.end())continue;
    v[j+1][itr - d.begin()]+=v[j][i];
    v[j+1][itr - d.begin()]%=mo;
  }
  rep(i,n-1){
    v[j+1][i+1]+=v[j+1][i];
    v[j+1][i+1]%=mo;
  }
}
ans=accumulate(v[3].begin(),v[3].end(),0LL);
ans%=mo;
cout << ans << endl;
return 0;
}