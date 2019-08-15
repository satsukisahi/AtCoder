#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
bool check(map<ll,ll> &m,ll a,ll se){
  if(m[a]>=se){
    if(a==1) return true;
    else {
      m.erase(a);
      m[a-1]++;
      if(check(m,a-1,se))return true;
    }
  }
  return false;
}
int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
bool c=1;
rep(i, n){
  cin >> a[i];
  if(i!=0&&a[i]<=a[i-1])c=0;
}
if(c){cout << 1 << endl;return 0;}
//upperは常に条件を満たすlowerは常に条件を満たさない
//条件を満たす最小のindexを返す
ll lower = 1; //上限のindex
ll upper = n; //上限のindex
ll seenow;
bool ok;
while (true)
{
  seenow = (lower + upper) / 2;

  //todo:seenowに対して処理
  //条件を満たすならok=true;にする 満たさないならok=false;
  map<ll,ll> m;
  ok=true;
  rep(i,n-1){
    if(a[i]==a[i+1]){
      m[a[i+1]]++;
      if(check(m,a[i+1],seenow)){ok=false;break;}
    }
    if(a[i]<a[i+1]){
    }
    if(a[i]>a[i+1]){
      m[a[i+1]]++;
      auto itr=m.find(a[i+1]);
      itr++;
      while(itr!=m.end()){
        itr=m.erase(itr);
      }
      if(check(m,a[i+1],seenow)){ok=false;break;}
    }
  }

  if (ok)
  {
    upper = seenow;
    if (upper == lower + 1)
    {
      ans = seenow;
      break;
    }
  }
  else
  {
    lower = seenow;
    if (upper == lower + 1)
    {
      ans = seenow + 1;
      break;
    }
  }
}
cout << ans << endl;
return 0;
}
