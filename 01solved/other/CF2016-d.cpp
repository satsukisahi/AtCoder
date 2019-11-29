#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> x(n);
rep(i, n){
  cin >> x[i];
}
sort(x.begin(),x.end());
vector<vector<ll>> v(m);
rep(i,n)v[x[i]%m].push_back(x[i]);
rep(i,(m-1)/2){
  ll ind=m-1-i,num=0;
  if(v[i+1].size()>v[m-1-i].size())ind=i+1;
  rep(j,v[ind].size()){
    if(j!=v[ind].size()-1&&v[ind][j]==v[ind][j+1]){num+=2;j++;}
  }
  ans+=min(v[i+1].size(),v[m-1-i].size())+min(num/2,abs((ll)v[i+1].size()-(ll)v[m-1-i].size())/2);
}
ans+=v[0].size()/2;
if(m%2==0)ans+=v[m/2].size()/2;
cout << ans << endl;
return 0;
}