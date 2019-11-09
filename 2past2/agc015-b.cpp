#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
string s ;
cin >> s ;
ll n=s.size();
rep(i,n){
  if(s[i]=='U'){
    ans+=n-1-i;
    ans+=2*i;
  }
  else{
    ans+=2*(n-1-i);
    ans+=i;
  }
}
cout << ans << endl;
return 0;
}