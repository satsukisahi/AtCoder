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
  set<ll> see;
  ll temp=0;
  ll now=c;
  while(see.find(now)==see.end()&&see.find(n-now-1)==see.end()){
    temp+=s[now];
    temp+=s[n-now-1];
    see.insert(now);
    if(see.find(n-now-1)==see.end())see.insert(n-now-1);
    else break;
    now+=c;
    ans=max(ans,temp);
    if(n-now-1<c)break;
  }
  c++;
}
cout << ans << endl;
return 0;
}
