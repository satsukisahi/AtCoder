#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
struct point {
    ll x,y,val;
    point() {}
    point(ll x, ll y, ll val) : x(x), y(y), val(val) {};
    point(ll x, ll y) : x(x), y(y), val(0) {};
};
bool cmp(const point &a, const point &b){
  if(a.y!=b.y)return a.y < b.y;
  return a.x < b.x;
}
int main()
{
ll n ;
cin >> n ;
vector<point> v;

rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  v.emplace_back(a,b,i);
}
sort(v.begin(),v.end(),cmp);
ll cnt=0;
ll ed=0;
vector<ll> vv;
rep(i,n){
  if(ed<=v[i].x){
    cnt++;
    ed=v[i].y;
    vv.push_back(v[i].val+1);
  }
}
cout << cnt << endl;
for(ll an:vv)cout << an << endl;
return 0;
}