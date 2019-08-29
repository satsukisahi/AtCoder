#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
string s ;
cin >> s ;
ll n=s.size();
if(s[0]=='0'||s[n-2]=='0'||s[n-1]=='1'){
cout << -1 << endl;
return 0;
}
ll pre=1;
vector<ll> ans;
rep(i,n-1){
  if(s[i]=='1'){
    if(s[n-i-2]=='1'){
      ans.push_back(i+2);
      ans.push_back(pre);
      pre=i+2;
    }
    else{cout << -1 << endl;return 0;}
  }
  else{
    if(s[n-i-2]=='0'){
      ans.push_back(i+2);
      ans.push_back(pre);
    }
    else{cout << -1 << endl;return 0;}
  }
}
rep(i,n-1){
  cout << ans[i*2]<< " "  << ans[i*2+1] << endl;
}

return 0;
}
