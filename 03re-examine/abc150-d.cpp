#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> a(n);
bool sa=1;
rep(i, n){
  cin >> a[i];
  if(i>0&&a[i-1]!=a[i])sa=0;
}
rep(i,n)a[i]/=2;
if(sa){
cout << ((m/a[0])+1)/2 << endl;
return 0;
}
bool aa=1;
auto b=a;
while(aa){
  aa=0;
  bool bb=0;
  rep(i,n){
    if(a[i]%2==0){
      bb=1;
      aa=1;
      a[i]/=2;
    }
    else{
      if(bb){
        cout << 0 << endl;
        return 0;
      }
    }
  }
}
ll r=b[0];
ll an=b[0];
rep(i,n-1){
  r=__gcd(an,b[i+1]);
  an*=b[i+1]/r;
  if(an >m){
cout << 0 << endl;
return 0;
  }
}
ans=((m/an)+1)/2;
cout << ans << endl;
return 0;
}