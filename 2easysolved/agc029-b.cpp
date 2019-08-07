#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n ;
multiset<ll> s;
ll ma=0;
rep(i, n){
  ll a;
  cin >> a;
  ma=max(ma,a);
  s.insert(a);
}
ll tar=1LL<<(64-__builtin_clzll(ma)+1);
while(tar!=1){
  auto itr=s.lower_bound(tar);
  ll siz=s.size();
  while(itr!=s.begin()){
    itr--;
    if(*itr<tar/2)break;
    auto fin=s.find(tar-*itr);
    if(fin!=s.end()&&*itr!=tar/2){
      ans++;
      s.erase(fin);
      itr=s.erase(itr);
    }
    else if(fin!=s.end()&&s.count(*itr)>1){
      ans+=s.count(*itr)/2;
      s.erase(*itr);
      break;
    }
  }
  tar/=2;
}

cout << ans << endl;
return 0;
}
