#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
vector<ll> ans(n*n);
rep(i, n){
  cin >> a[i];
  ans[a[i]-1]=i+1;
}
deque<ll> q;
rep(i,n*n){
  if(ans[i]!=0){
    rep(j,ans[i]-1)q.push_back(ans[i]);
  }
}
rep(i,n*n){
  if(ans[i]!=0){
    rep(j,q.size()){
      if(q[j]==ans[i]){
        cout << "No"<< endl;
        return 0;
      }
    }
    rep(j,n-ans[i]){
      q.push_back(ans[i]);
    }
  }
  else {
    if(q.empty()){
      cout << "No"<< endl;
      return 0;
    }
    ans[i]=q.front();
    q.pop_front();
  }
}
cout << "Yes"<< endl;
for(auto an:ans)cout << an << " ";
cout << endl;
return 0;
}