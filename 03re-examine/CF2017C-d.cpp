#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
string s ;
cin >> s ;
vector<ll> v(s.size()+1,0);
rep(i,s.size()){
  v[i+1]=v[i]^(1LL<<(s[i]-'a'));
}
map<ll,ll> m;
m[0]=0;
rep(i,s.size()){
  ll mi=1LL<<40;
  rep(j,27){
    ll r=1LL<<j;
    if(j==26)r=0;
    if(m.find(v[i+1]^r)!=m.end()){
      if(r==0)mi=min(mi,m[v[i+1]^r]-1);
      else mi=min(mi,m[v[i+1]^r]);
    }
  }
  m[v[i+1]]=mi+1;
}

cout << (m[v[s.size()]]==0?1:m[v[s.size()]]) << endl;
return 0;
}