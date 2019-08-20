#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
string s;
cin >>s;
ll index=0;
string a="";
string pre="";
while(index!=s.size()){
  ans++;
  a+=s[index];
  index++;
  if(index==s.size()){if(pre.size()==1&&pre[0]==a[0]){ans--;break;}}
  if(a==pre){a+=s[index];index++;}
  pre=a;
  a="";
}

cout << ans << endl;
return 0;
}
