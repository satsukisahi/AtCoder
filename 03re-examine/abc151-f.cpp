#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans=1000000;
struct point
{
  double x, y, val;
  point() {}
  point(double x, double y, double val) : x(x), y(y), val(val){};
  point(double x, double y) : x(x), y(y), val(0){};
};
struct vec
{
  double x, y;
  vec() {}
  vec(double x, double y) : x(x), y(y){};
  vec(point a, point b) : x(b.x - a.x), y(b.y - a.y){};
  double size() { return sqrt(x * x + y * y); };
};
//3点が一直線上にあるとtrue
bool threepoint(point a,point b,point c){
  return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)==0;
}
//先に一直線上にないか確認
point threepoint_circle(point a,point b,point c){
  point p;
  double k=((c.x-a.x)*(c.x-b.x)+(c.y-a.y)*(c.y-b.y))/((b.y-a.y)*(c.x-a.x)-(b.x-a.x)*(c.y-a.y));
  p.x=(a.x+b.x+k*(b.y-a.y))/2;
  p.y=(a.y+b.y-k*(b.x-a.x))/2;
  p.val=sqrt(p.x*p.x+p.y*p.y-a.x*b.x-a.y*b.y-k*a.x*(b.y-a.y)+k*a.y*(b.x-a.x));
  return p;
}

int main()
{
ll n ;
cin >> n ;
vector<point> v(n);
rep(i, n){
  cin >> v[i].x >> v[i].y;
}
vector<point> p;
rep(i,n-1)for (ll j = i+1; j < n; j++)
{
  p.emplace_back(v[i].x+vec(v[i],v[j]).x/2,v[i].y+vec(v[i],v[j]).y/2,vec(v[i],v[j]).size()/2);
}
rep(i,n-2)for (ll j = i+1; j < n-1; j++)for (ll k = j+1; k < n; k++){
  if(threepoint(v[i],v[j],v[k]))continue;
  p.push_back(threepoint_circle(v[i],v[j],v[k]));
}
for(auto r:p){
  bool ok=1;
  rep(i,n){
    if(vec(r,v[i]).size()>r.val){ok=0;break;}
  }
  if(ok)ans=min(ans,r.val);
}
cout<<fixed<<setprecision(12)<<ans<<endl;
return 0;
}