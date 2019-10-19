#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i,n){
  ll r;
  cin >> r;
  a[r-1]=i+1;
}
set<ll> s;
s.insert(0);
s.insert(n+1);
rep(i,n){
  auto itr=s.insert(a[i]).first;
  auto itr1=itr;itr1++;
  auto itr2=itr;itr2--;
  ans+=(i+1)*(*itr1-*itr)*(*itr-*itr2);
}
cout << ans << endl;
return 0;
}