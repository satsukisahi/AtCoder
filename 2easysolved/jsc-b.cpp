#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> r[n];
rep(i,n){
  string s ;
  cin >> s ;
  rep(j,n){
    if(s[j]=='1')r[j].push_back(i);
  }
}
string b[n];
ll ans[n][n]={};
char ch[n][n];
rep(i,n)rep(j,n)ch[i][j]='0';
rep(i,n){
  cin >> b[i] ;
}
rep(i,n){
  rep(j,n){
    bool ok=1;
    for(auto a:r[i]){
      if(b[a][j]=='0')ok=0;
    }
    if(ok){
      ans[i][j]=1;
      for(auto a:r[i]){
        ch[a][j]='1';
      }
    }
  }
}
rep(i,n)rep(j,n){
  if(b[i][j]!=ch[i][j]){
    cout << -1 << endl;
    return 0;
  }
}
rep(i,n){
  rep(j,n){
  cout << ans[i][j] ;
  }
  cout << endl;
}
return 0;
}