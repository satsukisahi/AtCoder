#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , a , b ;
cin >> n >> a >> b ;
if(a+b-1>n){
  cout << -1 << endl;
  return 0;
}
vector<ll> ans;
ll cb=0;
vector<ll> te;
rep(i,n){
  te.push_back(n-i);
  if(te.size()==a||i==n-1){
    ll t=te.size();
    rep(j,t){
      ans.push_back(te.back());
      te.pop_back();
    }
    cb++;
    if(cb>b){
      cout << -1 << endl;
      return 0;
    }
  }
}
ll nok=b-cb;
ll it=0;
rep(i,nok){
  if(ans[n-1-it]>ans[n-2-it])it++;
  else it+=2;
}
sort(ans.begin()+n-it-1, ans.end(), greater<ll>());
for(auto rr:ans)cout << rr << " ";
cout << endl;
return 0;
}