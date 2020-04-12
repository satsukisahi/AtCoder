#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
string s ;
cin >> s ;
vector<vector<ll>> v(n+1, vector<ll>(3,0) );
rep(i,n){
  v[i+1][0]=v[i][0];
  v[i+1][1]=v[i][1];
  v[i+1][2]=v[i][2];
  if(s[i]=='R')v[i+1][0]++;
  if(s[i]=='G')v[i+1][1]++;
  if(s[i]=='B')v[i+1][2]++;
}
char p[3]={'R','G','B'};
for (ll i = 0; i < n-1; i++)
{
  for (ll j = i+1; j < n; j++)
  {
    if(s[i]==s[j])continue;
    bool a[3]={};
    if(s[i]=='R')a[0]=1;
    if(s[j]=='R')a[0]=1;
    if(s[i]=='G')a[1]=1;
    if(s[j]=='G')a[1]=1;
    if(s[i]=='B')a[2]=1;
    if(s[j]=='B')a[2]=1;
    ll b;
    rep(u,3)if(!a[u]){b=u;break;}
    ans+=v[n][b]-v[j][b];
    if(j+j-i<n&&s[j+j-i]==p[b])ans--;
  }
  
}


cout << ans << endl;
return 0;
}