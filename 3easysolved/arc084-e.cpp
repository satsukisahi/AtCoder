#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll k , n ;
cin >> k >> n ;
if(k%2==0){
  cout << k/2 << ' ';
  rep(i,n-1)cout << k << ' ';
  cout << endl;
}
else{
  vector<ll> v;
  rep(i,n)v.push_back(k/2+1);
  ll s=n-1;
  rep(i,n/2){
    v[s]--;
    if(v[s]==0)s--;
    else{
      for(ll j=s+1;j<n;j++)v[j]=k;
      s=n-1;
    }
  }
  rep(i,n){
    if(v[i]==0)break;
    cout << v[i] << ' ';
  }
  cout << endl;
}
return 0;
}