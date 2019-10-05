#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;

int main()
{
  auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
  ll n;
  cin >> n;
  string x;
  cin >> x;
  ll oth = 0;
  vector<ll> ii;
  ll tt = 1;
  rep(i, n)
  {
    ii.push_back(tt);
    tt *= 2;
    tt %= mo;
  }
  map<ll, ll> m;
  for (ll i = n % 2 ? n : n - 1; i >= 3; i -= 2)
  {
    if (n % i == 0)
    {
      ll cou = 1;
      ll tem = 0;
      rep(j, (n / i))
      {
        if (x[j] == '1')
        {
          tem *= 2;
          tem++;
          tem %= mo;
        }
        else
        {
          tem *= 2;
          tem %= mo;
        }
      }
      tem++;
      while (1)
      {
        bool ng = 0;
        rep(j, (n / i))
        {
          if (cou % 2 && x[j] == '1' && x[j + cou * (n / i)] == '1')
          {
            ng = 1;
            break;
          }
          else if (cou % 2 && x[j] == '0' && x[j + cou * (n / i)] == '0')
          {
            ng = 1;
            tem--;
            break;
          }
          else if (cou % 2 == 0 && x[j] == '1' && x[j + cou * (n / i)] == '0')
          {
            ng = 1;
            tem--;
            break;
          }
          else if (cou % 2 == 0 && x[j] == '0' && x[j + cou * (n / i)] == '1')
          {
            ng = 1;
            break;
          }
        }
        if (ng)
          break;
        cou++;
        if (cou >= i)
          break;
      }
      if (tem < 0)
        tem = 0;
      for (auto j = m.begin(); j != m.end(); ++j)
      {
        if ((n / i) % j->first == 0 && ((n / i) / j->first) % 2)
          tem -= j->second;
      }
      m[(n / i)] = tem;
      oth += tem;
      oth %= mo;
      ans += tem * (n / i) * 2;
      ans %= mo;
      cout << tem*(n/i)*2 <<" " << tem << endl;
    }
  }
  ll num = 0;
  rep(i, n)
  {
    if (x[i] == '1')
      num += ii[n - 1 - i];
    num %= mo;
  }
  ans += mod(num - oth + 1) * x.size() * 2;
  cout << ans % mo << endl;
  return 0;
}
