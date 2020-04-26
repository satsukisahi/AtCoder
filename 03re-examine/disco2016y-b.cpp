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
rep(i, n){
  cin >> a[i];
}
if(*max_element(a.begin(),a.end())==a[0])a[0]=0;
vector<vector<ll>> v(100001);
rep(i,n)v[a[i]].push_back(i);
ll w=-1;
rep(i,100001){
  ll b=-1;
  for(auto r:v[i]){
    if(r<w)continue;
    if(b==-1)b=r;
    w=r;
  }
  for(auto r:v[i]){
    if(r==b)break;;
    if(w>r)ans++;
    w=r;
  }
}
cout <<ans+1<< endl;
return 0;
}