#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
vector<ll> b(n);
rep(i, n){
  a[i]+=i*n;
  b[i]+=(n-i-1)*n;
  ll r;
  cin >> r;
  b[r-1]+=i;
}
for(auto an:a)cout << an+1 << " ";
cout << endl;
for(auto an:b)cout << an+1 << " ";
cout << endl;
return 0;
}