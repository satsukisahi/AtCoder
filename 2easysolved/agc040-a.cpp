#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
string s ;
cin >> s ;
vector<ll> v(s.size()+1);
rep(i,s.size()){
  if(s[i]=='<')v[i+1]=v[i]+1;
}
rep(i,s.size()){
  if(s[s.size()-i-1]=='>')v[s.size()-i-1]=max(v[s.size()-i]+1,v[s.size()-i-1]);
}

auto ans=accumulate(v.begin(),v.end(),0LL);
cout << ans << endl;
return 0;
}