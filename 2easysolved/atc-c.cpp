#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;
const ll mo = 1000000007;
vector<ll> factorial(ll n){
  vector<ll> fac;
  fac.push_back(1);
  for(ll i = 1; i < n; i++){
      fac.push_back((fac[i-1]*i)%mo);
  }
  return fac;
}
int main()
{
ll n ;
string  s ;
cin >> n >> s ;
bool a[2*n]={};
if(!(s[0]=='B'&&s[2*n-1]=='B')){
  cout << 0 << endl;
  return 0;
}
ll aa=0;
rep(i,n*2){
  if(i%2==1&&s[i]=='B'){a[i]=1;aa++;}
  if(i%2==0&&s[i]=='W'){a[i]=1;aa++;}
}
if(aa!=n){
  cout << 0 << endl;
  return 0;
}

ll te=0;
rep(i,2*n){
  if(a[2*n-1-i]==1)te++;
  else{
    ans*=te;
    te--;
    ans%=mo;
  }
}
vector<ll> fac=factorial(100100);
ans*=fac[n];
ans%=mo;
cout << ans << endl;
return 0;
}
