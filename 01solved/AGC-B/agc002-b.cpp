#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> num(n,1);
vector<bool> ok(n);
ok[0]=1;
rep(i,m){
  ll x , y ;
  cin >> x >> y ;
  x--;y--;
  if(num[x]>1&&ok[x]){
    num[x]--;
    num[y]++;
    ok[y]=1;
  }
  else if(num[x]==1&&ok[x]){
    num[x]--;
    ok[x]=0;
    num[y]++;
    ok[y]=1;
  }
  else{
    num[x]--;
    num[y]++;
  }
}
for(auto an:ok)if(an)ans++;
cout << ans << endl;
return 0;
}