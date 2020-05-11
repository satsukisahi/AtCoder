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
  return a.x > b.x;
}
bool cmp2(const point &a, const point &b){
  return a.y < b.y;
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
ll ed=1LL<<25;
vector<ll> vv;
rep(i,n){
  if(ed>=v[i].y){
    cnt++;
    ed=v[i].x;
    vv.push_back(v[i].x);
  }
}
reverse(vv.begin(),vv.end());
vv.push_back(1LL<<25);
sort(v.begin(),v.end(),cmp2);
auto c = [](point l, point r) { return l.val>r.val;};
cout << cnt << endl;
priority_queue<point, vector<point>, decltype(c)> q(c);

ll itr=0,num=0;
ed=0;
while(num<cnt){
while(itr<n&&v[itr].y<=vv[num+1]){
  q.push(v[itr]);
  itr++;
}
while(1){
  auto r=q.top();q.pop();
  if(ed<=r.x){
    if(num+1==cnt)cout << r.val+1 ;
    else cout << r.val+1 << " ";
    ed=r.y;
    num++;
    break;
  }
}
}
cout <<endl;
return 0;
}