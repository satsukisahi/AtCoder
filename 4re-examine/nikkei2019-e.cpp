#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , k ;
cin >> n >> k ;
if((k+k+2*n-1)*2*n/2>(k+2*n+k+3*n-1)*n/2){
cout << -1 << endl;
return 0;
}
ll a=k,b=(n+1)/2+n+k-1;
ll nu=0;
while(1){
  cout << a << " " << b << " " << k+2*n+nu << endl;
  a+=2;
  b--;
  nu++;
  if(a>=n+k)break;
}
a=k+1;
b=k+2*n-1;
while(1){
  if(a>=n+k)break;
  cout << a << " " << b << " " << k+2*n+nu << endl;
  a+=2;
  b--;
  nu++;
  if(a>=n+k)break;
}
return 0;
}