#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> s(n);
rep(i, n){
  cin >> s[i];
}
ll c=1;
while(c<n/2){
while(1){
  ll see[n]={};
  ll temp=0;
  ll now=0;
  now+=c;
  if(see[now]==0&&see[n-now-1]==0){
    temp+=s[now];
    temp+=see[n-now-1];
    see[now]=1;
    see[n-now-1]=1;
    now+=c;
    ans=max(ans,temp);
    }
  else break;
}
c++;
}
cout << ans << endl;
return 0;
}
