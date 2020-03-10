#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , p ;
cin >> n >> p ;
string s ;
cin >> s ;
auto mod = [&](ll modx) {modx%=p;modx+=p;modx%=p;return modx; };
vector<ll> v;
rep(i,n){
  v.push_back(s[i]-'0');
}
if(p==2||p==5){
  rep(i,n){
    if(v[i]%p==0)ans+=i+1;
  }
}
else{
vector<ll> a(p);
vector<ll> b(n);
ll k=1,kk=0;
rep(i,n){
  kk=mod(k*v[n-1-i]+kk);
  a[kk]++;
  b[n-i-1]=kk;
  k=mod(k*10);
}
a[0]++;
rep(i,n){
  ans+=a[b[i]]-1;
  a[b[i]]--;
}

}
cout << ans << endl;
return 0;
}