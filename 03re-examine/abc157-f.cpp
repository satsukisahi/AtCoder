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
struct vec
{
  double x, y;
  vec() {}
  vec(double x, double y) : x(x), y(y){};
  vec(point a, point b) : x(b.x - a.x), y(b.y - a.y){};
  double size() { return sqrt(x * x + y * y); };
};
vector<point> circle_intersection(point c1,double r1,point c2,double r2){
  vector<point> res;
  if(r1+r2==vec(c1,c2).size()||fabs(r1-r2)==vec(c1,c2).size()){
    point p(vec(c1,c2).x*r1/vec(c1,c2).size()+c1.x,vec(c1,c2).y*r1/vec(c1,c2).size()+c1.y);
    res.push_back(p);
  }
  else if(r1+r2>vec(c1,c2).size()&&fabs(r1-r2)<vec(c1,c2).size()){
    double di=vec(c1,c2).size()*vec(c1,c2).size();
    double li=(di+r1*r1-r2*r2)/2;
    point p1(c1.x+(li*(-c1.x+c2.x)+(-c1.y+c2.y)*sqrt(di*r1*r1-li*li))/di,c1.y+(li*(-c1.y+c2.y)-(-c1.x+c2.x)*sqrt(di*r1*r1-li*li))/di);
    res.push_back(p1);
    point p2(c1.x+(li*(-c1.x+c2.x)-(-c1.y+c2.y)*sqrt(di*r1*r1-li*li))/di,c1.y+(li*(-c1.y+c2.y)+(-c1.x+c2.x)*sqrt(di*r1*r1-li*li))/di);
    res.push_back(p2);
  }
  return res;
}


int main()
{
ll n , k ;
cin >> n >> k ;
vector<point> p;
rep(i,n){
  ll x , y , c ;
  cin >> x >> y >> c ;
  p.emplace_back(x,y,c);
}
auto judge_d = [&](double val) { 
  vector<point> v;
  rep(i,n)v.push_back(p[i]);
  rep(i,n-1)for (ll j = i+1; j < n; j++)
  {
    if(p[i].x==p[j].x&&p[i].y==p[j].y)continue;
    auto r=circle_intersection(p[i],val/p[i].val,p[j],val/p[j].val);
    for(auto rr:r)v.push_back(rr);
  }
  for(auto r:v){
    ll cnt=0;
    rep(i,n){
      if(vec(r,p[i]).size()<=val/p[i].val+0.0000001)cnt++;
    }
    if(cnt>=k)return false;
  }
  return true;
};
auto binarysearch_d = [&](double lowerbound, double upperbound) {
  if (!judge_d(lowerbound)) return 0.0;
  double lower = lowerbound, upper = upperbound;
  while (1){
    if (judge_d((lower + upper) / 2)) lower = (lower + upper) / 2;
    else upper = (lower + upper) / 2;
    if (fabs(upper - lower) <= 0.0000001){
      return upper;
    }
  }
};
double ans=binarysearch_d(0, 1000000);
cout<<fixed<<setprecision(12)<<ans<<endl;

return 0;
}