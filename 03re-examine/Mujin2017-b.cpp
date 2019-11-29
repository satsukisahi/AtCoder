#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<string> s(n);
rep(i, n){
  cin >> s[i];
}
bool ok=0;
rep(i,n)rep(j,n)if(s[i][j]=='#')ok=1;
if(!ok){
cout << -1 << endl;
return 0;
}
ll y=0,t=0;
rep(i,n){
  bool k=1;
  rep(j,n){
    if(s[i][j]=='.')k=0;
  }
  if(k)y++;
}
rep(i,n){
  bool k=1;
  rep(j,n){
    if(s[j][i]=='.')k=0;
  }
  if(k)t++;
}
if(y>0){
cout << n-t << endl;
return 0;
}
ll p=9999;
rep(i,n){
  ll a=0;
  rep(j,n)if(s[i][j]=='.')a++;
  bool k=0;
  rep(j,n)if(s[j][i]=='#')k=1;
  if(!k&&a==n)continue;
  if(!k)a++;
  p=min(a,p);
}
cout << p+n-t << endl;
return 0;
}