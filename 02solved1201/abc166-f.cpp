#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n;
vector<ll> p(3,0);
cin >> n >> p[0] >> p[1] >> p[2] ;
vector<vector<ll>> v(n, vector<ll>(3,0) );
vector<char> ans(n);

rep(i,n){
  string s;
  cin >> s;
  if(s=="AB"){v[i][0]++;v[i][1]++;}
  if(s=="AC"){v[i][0]++;v[i][2]++;}
  if(s=="BC"){v[i][1]++;v[i][2]++;}
}
if(p[0]+p[1]+p[2]>=3||p[0]+p[1]+p[2]<=1){
  rep(i,n){
    bool ok=0;
    ll ind=-1;
    rep(j,3){
      if(v[i][j]&&p[j]>0)ok=1;
      if(v[i][j]&&ind==-1){ind=j;}
      else if(v[i][j]){
        if(p[ind]>=p[j]){ans[i]='A'+j;p[j]++;p[ind]--;}
        else {ans[i]='A'+ind;p[j]--;p[ind]++;}
      }
    }
    if(!ok){cout << "No" << endl;return 0;}
  }
}
else{
  rep(i,n){
    bool ok=0;
    ll ind=-1;
    rep(j,3){
      if(v[i][j]&&p[j]>0)ok=1;
      if(v[i][j]&&ind==-1){ind=j;}
      else if(v[i][j]){
        if(p[ind]==1&&p[j]==1&&i!=n-1){
          if(v[i+1][ind]){ans[i]='A'+ind;p[j]--;p[ind]++;}
          else{ans[i]='A'+j;p[j]++;p[ind]--;}
        }
        else if(p[ind]>p[j]){ans[i]='A'+j;p[j]++;p[ind]--;}
        else {ans[i]='A'+ind;p[j]--;p[ind]++;}
      }
    }
    if(!ok){cout << "No" << endl;return 0;}
  }
}
cout << "Yes" << endl;
for(auto r:ans){
  cout << r << endl;
}
return 0;
}