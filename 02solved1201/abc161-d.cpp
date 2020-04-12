#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
vector<ll> v;
void dfs(ll a){
  if(a>3234566667)return;
  v.push_back(a);
  if(a%10!=9)dfs(a*10+a%10+1);
  if(a%10!=0)dfs(a*10+a%10-1);
  dfs(a*10+a%10);
}
int main()
{
ll k ;
cin >> k ;
rep(i,9)dfs(1+i);
sort(v.begin(),v.end());
cout << v[k-1] << endl;
return 0;
}