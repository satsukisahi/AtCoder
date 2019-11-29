#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> p(n);
rep(i, n){
  cin >> p[i];
}
vector<ll> pp(n);
ll a=0;
ll rr=0;
rep(i,n-1){
  if(p[i]<p[i+1])a++;
  else a=0;
  if(a>=k-1){
    pp[i-k+2]=1;
    rr++;
  }
}
set<ll> s;
rep(i,k){
  s.insert(p[i]);
}
rep(i,n-k){
  if(pp[i]==0){auto itrmi=s.begin();
  auto itrmx=s.end();itrmx--;
  if(*itrmi==p[i] && *itrmx<p[i+k])ans++;}
  s.erase(p[i]);
  s.insert(p[i+k]);
}
ll an=n-k+1-ans;
if(rr!=0){
  an-=rr-1;
}
cout << an << endl;
return 0;
}