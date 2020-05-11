#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
vector<ll> ans;


int main()
{
ll n , k , d ;
cin >> n >> k >> d ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
if(n<(k-1)*d+1){
cout << -1 << endl;
return 0;
}
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
rep(i,n-(k-1)*d)q.push({a[i],i});
auto p=q.top(); q.pop();
ll ind=p.second;
ans.push_back(p.first);

while(ans.size()<k){
  for (ll i = n-(k-1)*d-1+(ans.size()-1)*d +1; i <= n-(k-1)*d-1+ans.size()*d; i++)
  {
    q.push({a[i],i});
  }
  while(1){
    auto pp=q.top();q.pop();
    if(ind+d<=pp.second){
      ind=pp.second;
      ans.push_back(pp.first);
      break;
    }
  }
}
for(auto an:ans)cout << an << " " ;
cout << endl;
return 0;
}