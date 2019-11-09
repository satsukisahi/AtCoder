#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll n,k;
cin >> n >> k ;
vector<ll> v;
rep(i,n){
  ll r=n/(i+1);
  ll s=n/r;
  v.push_back(s-i);
  i=s-1;
}
ll ans[v.size()];
rep(i,v.size()){
  ans[i]=v[i];
}
ll sum[v.size()];
rep(i,k){
  rep(j,v.size()){
    if(j==0)sum[0]=ans[0];
    else {sum[j]=ans[j]+sum[j-1];sum[j]%=mo;}
  }
  rep(j,v.size()){
    ans[j]=v[j]*sum[v.size()-j-1];
    ans[j]%=mo;
  }
}

cout << sum[v.size()-1] << endl;
return 0;
}
