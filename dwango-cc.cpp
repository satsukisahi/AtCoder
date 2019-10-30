#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
string s ;
cin >> s ;
ll q ;
cin >> q ;
vector<ll> k(q);
rep(i, q){
  cin >> k[i];
}
rep(i,q){
ll nummc=0,numm=0,numc=0,ans=0;
rep(j,k[i]){
  if(s[j]=='M')numm++;
  if(s[j]=='C'){numc++;nummc+=numm;}
}
rep(j,n-k[i]){
  if(s[j]=='D')ans+=nummc;
  if(s[j]=='M'){nummc-=numc;numm--;}
  if(s[j]=='C')numc--;
  if(s[j+k[i]]=='M')numm++;
  if(s[j+k[i]]=='C'){numc++;nummc+=numm;}
}
rep(j,k[i]){
  if(s[n-k[i]+j]=='D')ans+=nummc;
  if(s[n-k[i]+j]=='M'){nummc-=numc;numm--;}
  if(s[n-k[i]+j]=='C')numc--;
}
cout << ans << endl;
}
return 0;
}