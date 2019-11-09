#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> a(n);
ll sum=0;
rep(i, n){
  cin >> a[i];
  sum+=a[i];
}
sort(a.rbegin(), a.rend());
vector<int> yaku;
for (int i = 1; i*i <= sum; i++)
{
  if (sum % i == 0)
  {
    yaku.push_back(i);
    if(sum/i!=i)yaku.push_back(sum / i);
  }
}
sort(yaku.rbegin(), yaku.rend());
rep(i,yaku.size()){
  ll h=yaku[i];
  ll eps=0;
  ll count=0;
  vector<ll> aa;
  rep(j,n){
    aa.push_back(a[j]-(a[j]/h)*h);
    eps+=aa[j];
  }
  sort(aa.rbegin(), aa.rend());
  rep(j,eps/h){
    count+=h-aa[j];
  }
  if(count<=k){
    cout << h << endl;
    return 0;
  }
}

return 0;
}
