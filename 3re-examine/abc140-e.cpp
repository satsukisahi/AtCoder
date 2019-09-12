#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> p(n);
vector<ll> ind(n+1);
rep(i, n){
  cin >> p[i];
  ind[p[i]]=i;
}
set<ll> s;
s.insert(-1);
s.insert(n);
rep(i,n){
  auto itr=s.insert(ind[n-i]);
  auto itr0=itr.first;
  auto itr1=itr.first;
  auto itr2=itr.first;
  itr1--;itr2++;
  if(*itr1!=-1){
    auto itr3=itr1;
    itr3--;
    ans+=(*itr1-*itr3)*(*itr2-*itr0)*(n-i);
  }
    if(*itr2!=n){
    auto itr4=itr2;
    itr4++;
    ans+=(*itr4-*itr2)*(*itr0-*itr1)*(n-i);
  }
}


cout << ans << endl;
return 0;
}
