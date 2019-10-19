#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , x ;
cin >> n >> x ;
if(x==1||x==2*n-1){
  cout << "No" << endl;
}
else if(n==2){
  cout << "Yes" << endl;
  cout << 1 << endl;
  cout << 2 << endl;
  cout << 3 << endl;
}
else{
  cout << "Yes" << endl;
  vector<ll> ans(2*n-1);
  set<ll> s;
  if(x==2){
    ans[n-2]=x+2;s.insert(x+2);
    ans[n-1]=x;s.insert(x);
    ans[n]=x-1;s.insert(x-1);
    ans[n+1]=x+1;s.insert(x+1);
  }
  else{
    ans[n-2]=x-2;s.insert(x-2);
    ans[n-1]=x;s.insert(x);
    ans[n]=x+1;s.insert(x+1);
    ans[n+1]=x-1;s.insert(x-1);
  }
  ll st=1;
  rep(i,2*n-1){
    if(ans[i]!=0)continue;
    while(s.find(st)!=s.end())st++;
    ans[i]=st;
    st++;
  }
  for(auto an:ans){
    cout << an << endl;
  }
}
return 0;
}