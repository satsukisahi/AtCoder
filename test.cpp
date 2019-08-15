#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
map<ll,ll> m;
m[3]=9;
m[2]=4;
m[5]=2;
m[9]=6;
auto itr=m.find(3);
itr++;
while(itr!=m.end()){
        itr=m.erase(itr);
      }
cout << ans << endl;
return 0;
}
