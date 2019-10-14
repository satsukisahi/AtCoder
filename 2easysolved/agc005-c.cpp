#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
multiset<ll> a;
rep(i, n){
  ll b;
  cin >> b;
  a.insert(b);
}
auto itrmx=a.end();
itrmx--;
auto itrmi=a.begin();
bool ok=1;
if((*itrmx+1)/2!=*itrmi)ok=0;
if(*itrmx%2==0 && a.count(*itrmi)!=1)ok=0;
if(*itrmx%2==1 && a.count(*itrmi)!=2)ok=0;
for (ll i = *itrmi; i <= *itrmx; i++)
{
  if(a.count(i)==0)ok=0;
}


if(ok)cout << "Possible" << endl;
else cout << "Impossible" << endl;
return 0;
}