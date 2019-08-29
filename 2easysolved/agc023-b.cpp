#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
char s[n][n];
rep(i,n)rep(j,n){
  cin >> s[i][j];
}
ll t[n][n]={};
rep(i,n)rep(j,n){
  rep(k,n-1){
    if(s[(i+k+1)%n][j]!=s[i][(j+k+1)%n]){
      t[i][j]=k;
      break;
    }
    if(k==n-2)t[i][j]=n-1;
  }
}
rep(i,n)rep(j,n){
  bool ok=1;
  rep(k,n-1){
    if(t[(i+k)%n][(j+k)%n]<n-1-k){ok=0;break;}
  }
  if(ok)ans++;
}

cout << ans << endl;
return 0;
}
