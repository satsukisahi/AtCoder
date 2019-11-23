#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;

int main()
{
string s ;
cin >> s ;
ll r=0,b=0;
rep(i,s.size()){
  if(s[i]=='0')r+=2;
  else if(s[i]=='2')b+=2;
  else {r++;b++;}
}
vector<ll> rr,bb;
rr.push_back(0);
bb.push_back(0);
rep(i,s.size()){
  if(s[i]=='0'){
    rr.push_back(rr.back()+2);
    bb.push_back(bb.back());
  }
  if(s[i]=='1'){
    rr.push_back(rr.back()+1);
    bb.push_back(bb.back()+1);
  }
  if(s[i]=='2'){
    bb.push_back(bb.back()+2);
    rr.push_back(rr.back());
  }
}
while(rr.size()!=2*s.size()+1)rr.push_back(rr.back());
while(bb.size()!=2*s.size()+1)bb.push_back(bb.back());
vector<vector<ll>> v(s.size()*2, vector<ll>(r+1,0) );
if(s[0]=='0')v[0][1]=1;
if(s[0]=='1'){v[0][0]=1;v[0][1]=1;}
if(s[0]=='2')v[0][0]=1;
rep(i,s.size()*2-1){
  rep(j,r+1){
    if(i+2-j<=bb[i+2]){
      v[i+1][j]+=v[i][j];
      v[i+1][j]%=mo;
    }
    if(j+1<=rr[i+2]){
      v[i+1][j+1]+=v[i][j];
      v[i+1][j+1]%=mo;
    }
  }
}
cout << v[s.size()*2-1][r] << endl;
return 0;
}