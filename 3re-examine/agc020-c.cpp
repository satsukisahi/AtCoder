#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , sum=0 ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
  sum+=a[i];
}
bitset<4000001> b;
b[0]=1;
rep(i,n){
  b|=(b<<a[i]);
}
ll r=(sum+1)/2;
while(1){
  if(b[r]){
    cout << r << endl;
    break;
  }
  r++;
}
return 0;
}