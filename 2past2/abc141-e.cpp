#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
vector< int > z_algorithm(const string &s) {
  vector< int > prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}
int main()
{
ll n ;
cin >> n ;
string s ;
cin >> s ;

rep(i,n){
  auto v=z_algorithm(s);
  rep(j,v.size()-1){
    if(j>=v[j+1]-1)
    ans=max((int)ans,v[j+1]);
  }
  s.erase(0,1);
}
cout << ans << endl;
return 0;
}