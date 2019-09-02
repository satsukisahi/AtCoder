#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll num=26;
string a ;
cin >> a ;
vector<ll> ans;
bool r[num]={};
ll dp[a.size()]={};
ll sy=0;
ll le=1;
for (ll i = a.size()-1; i >=0 ; i--)
{
  dp[i]=le;
  if(!r[a[i]-'a']){r[a[i]-'a']=1;sy++;}
  if(sy==num){
    rep(j,num)r[j]=0;
    sy=0;
    le++;
  }
}
char c='a';
bool ok=1;
rep(j,num)r[j]=0;
rep(i,a.size()){
  if(le!=dp[i]){
    le=dp[i];
    ok=0;
    rep(j,num){
      if(!r[j]){ans.push_back(j);
      c='a'+j;
      break;}
    }
    rep(j,num)r[j]=0;
  }

  if(ok){
    r[a[i]-'a']=1;
  }
  if(a[i]==c&&!ok){
    ok=1;
  }
}
rep(j,num){
  if(!r[j]){ans.push_back(j);
  break;}
}

rep(i,ans.size()){
  char c='a'+ans[i];
  cout << c;
}
  cout << endl;

return 0;
}
