#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , m ;
cin >> n >> m ;
string s ;
cin >> s ;
vector<ll> ans;
ll now=n;
while(1){
  bool b=0;
  for(ll i=m;i>0;i--){
    if(now-i>=0&&s[now-i]=='0'){
      b=1;
      ans.push_back(i);
      now=now-i;
      break;
    }
  }
  if(b==0){
    cout << -1 << endl;
    return 0;
  }
  if(now==0)break;
}
reverse(ans.begin(),ans.end());
for(auto an:ans)cout << an << ' ';
cout << endl;
return 0;
}