#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll m ;
cin >> m ;
vector<ll> d(m);
vector<ll> c(m);
rep(i, m){
  cin >> d[i] >> c[i];
}

ll sum=0,keta=0;
rep(i,m){
  sum+=d[i]*c[i];
  keta+=c[i];
}
ans+=keta-1;
ans+=(sum-1)/9;
cout << ans << endl;
return 0;
}