#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
ll ans = 0;
bool prime(int num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
    {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main()
{
ll n, k;
cin >> n >> k;
vector<int> yaku;

{
  for (int i = 1; i*i <= k; i++)
  {
    if (k % i == 0)
    {
      yaku.push_back(i);
      if(k/i!=i)yaku.push_back(k / i);
    }
  }
  sort(yaku.begin(), yaku.end());
}
rep(i, yaku.size())
{
  vector<int> soin;
  int tempsoin = k/yaku[i];
  vector<int> yakua;
  for (int i = 1; i*i <= tempsoin; i++)
  {
    if (tempsoin % i == 0)
    {
      yakua.push_back(i);
      if(tempsoin/i!=i)yakua.push_back(tempsoin / i);
    }
  }
  sort(yakua.begin(), yakua.end());
  rep(i,yakua.size()){
    if(prime(yakua[i])){
      soin.push_back(yakua[i]);
    }
  }

  ll nn=n/yaku[i];

  ll anss=0;
  rep(l,1<<soin.size()){
    ll num=1;
    rep(ii,soin.size()){
      if(l>>ii&1LL)num*=soin[ii];
    }
    ll sum=(num+((nn/num)*num))*(nn/num)/2;
    sum%=mo;
    if(__builtin_popcount(l) % 2){
      anss=anss+mo-sum;
      anss%=mo;
    }
    else{
      anss=anss+sum;
      anss%=mo;
    }
  }
  ans+=anss;
  ans%=mo;
  //cout << anss<< endl;
}

cout << (ans*k)%mo << endl;
return 0;
}
