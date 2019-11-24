#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

vector<int> z_algorithm(const string &s)
{
  vector<int> prefix(s.size());
  for (int i = 1, j = 0; i < s.size(); i++)
  {
    if (i + prefix[i - j] < j + prefix[j])
    {
      prefix[i] = prefix[i - j];
    }
    else
    {
      int k = max(0, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k])
        ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int)s.size();
  return prefix;
}

int main()
{
  string s = "abbabbababbabc";
  string t = "abbab";
  //vはある位置から何文字先頭と一致しているかを返す
  // a b b a b | a b b a b b a b a b b a b c
  //20 0 0 2 0 0 5 0 0 5 0 0 2 0 5 0 0 2 0 0
  vector<int> v = z_algorithm(t + '|' + s);
  for (ll i = t.size() + 1; i < v.size(); i++)
  {
    if (v[i] == t.size())
      cout << i - (t.size() + 1) << endl; //0 3 8
  }
  //連続した一致を探すときに前から貪欲はNG
  return 0;
}
