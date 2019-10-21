#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
struct point
{
  double x, y, val;
  point() {}
  point(double x, double y, double val) : x(x), y(y), val(val){};
  point(double x, double y) : x(x), y(y), val(0){};
};
bool cmp(const point &a, const point &b){
  return a.x < b.x;
}
int main()
{
ll n,ans=0 ;
cin >> n ;
vector<point> r,b;
rep(i,n){
  ll l , k ;
  cin >> l >> k ;
  r.emplace_back(l,k);
}
rep(i,n){
  ll l , k ;
  cin >> l >> k ;
  b.emplace_back(l,k);
}
sort(b.begin(),b.end(),cmp);
vector<bool> rr(n); 
rep(i,n){
  ll y=-1,ind=-1;
  rep(j,n){
    if(b[i].x>r[j].x && b[i].y>r[j].y && r[j].y>y && rr[j]==0){
      ind=j;
      y=r[j].y;
    }
  }
  if(ind!=-1){
    rr[ind]=1;
    ans++;
  }
}

cout << ans << endl;
return 0;
}