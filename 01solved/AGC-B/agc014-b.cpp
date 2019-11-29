#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n,m;
cin >> n >> m ;
ll res[n]={};
rep(i, m)
{
  ll a,b;
  cin >> a>>b;
  res[a-1]++;
  res[b-1]++;
}

rep(i,n){
  if(res[i]%2){
    cout << "NO" << endl;
return 0;
  }
}
cout << "YES" << endl;
return 0;
}
