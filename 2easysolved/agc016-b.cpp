#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
bool same=1;
ll mx=0;
rep(i, n){
  cin >> a[i];
  mx=max(mx,a[i]);
}
rep(i,n-1)if(a[i]!=a[i+1])same=0;
if(same){
  if(n==a[0]+1 ||n>=a[0]*2){
    cout << "Yes" << endl;
    return 0;
  }
}
else{
  ll cnt=0;
  rep(i,n){
    if(a[i]==mx-1)cnt++;
    else if(a[i]<mx-1){
      cout << "No" << endl;
      return 0;
    }
  }
  if(n-cnt>=(mx-cnt)*2 && mx-cnt>0){
    cout << "Yes" << endl;
    return 0;
  }
}
cout << "No" << endl;
return 0;
}