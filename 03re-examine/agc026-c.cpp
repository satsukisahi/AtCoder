#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
string  s ;
cin >> n >> s ;
string f=s.substr(0,n);
string b=s.substr(n,n);
reverse(b.begin(), b.end());
map<pair<string,string>, long long > ma;
rep(i,1LL<<n){
  string re="",bl="";
  rep(j,n){
    if(i>>j&1LL)re+=f[j];
    else bl+=f[j];
  }
  pair<string,string> p={re,bl};
  ma[p]++;
}
rep(i,1LL<<n){
  string re="",bl="";
  rep(j,n){
    if(i>>j&1LL)re+=b[j];
    else bl+=b[j];
  }
  pair<string,string> p={re,bl};
  ans+=ma[p];
}
cout << ans << endl;
return 0;
}
