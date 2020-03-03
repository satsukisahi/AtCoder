#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
double pi = 3.1415926535897932;
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
//xの昇順で同じときyの昇順
bool cmp(const point &a, const point &b)
{
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
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
//2円の交点　同じ円は除く
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
//ベクトルabとベクトルbcにおけるbcに対して時計回りの角cba
double arg(vec a, vec b)
{
  if (a.x * b.y - a.y * b.x > 0)
    return acos((-a.x * b.x - a.y * b.y) / (a.size() * b.size())) * (-180) / pi + 360;
  else
    return acos((-a.x * b.x - a.y * b.y) / (a.size() * b.size())) * 180 / pi;
}
//線分abとcdの交差判定
bool judgeIentersected(point a, point b, point c, point d)
{
  double ta = (c.x - d.x) * (a.y - c.y) + (c.y - d.y) * (c.x - a.x);
  double tb = (c.x - d.x) * (b.y - c.y) + (c.y - d.y) * (c.x - b.x);
  double tc = (a.x - b.x) * (c.y - a.y) + (a.y - b.y) * (a.x - c.x);
  double td = (a.x - b.x) * (d.y - a.y) + (a.y - b.y) * (a.x - d.x);
  return tc * td < 0 && ta * tb < 0;
  //return tc * td <= 0 && ta * tb <= 0; // 端点を含む場合
}
//凸包　左（同じなら下）から時計回りに出力
vector<point> convex_hull(vector<point> &v)
{
  sort(v.begin(), v.end(), cmp);
  vector<point> res, res2;
  for (auto p : v)
  {
    if (res.size() < 2)
      res.push_back(p);
    else
    {
      while (arg(vec(res[res.size() - 2], res[res.size() - 1]), vec(res[res.size() - 1], p)) > 180.00001 && res.size() >= 2)
        res.pop_back();
      res.push_back(p);
    }
  }
  for (auto p : v)
  {
    if (res2.size() < 2)
      res2.push_back(p);
    else
    {
      while (arg(vec(res2[res2.size() - 2], res2[res2.size() - 1]), vec(res2[res2.size() - 1], p)) < 179.99999 && res2.size() >= 2)
        res2.pop_back();
      res2.push_back(p);
    }
  }
  rep(i, res2.size() - 2)
  {
    res.push_back(res2[res2.size() - i - 2]);
  }
  return res;
}
//凸包における最遠点対
vector<pair<point, point>> convex_diameter(vector<point> &v)
{
  ll st = 0;
  double mx = 0;
  vector<pair<point, point>> res;
  for (ll i = 1; i < v.size(); i++)
  {
    auto te = vec(v[st], v[i]);
    double tesize = te.size();
    if (tesize > mx)
    {
      mx = tesize;
      res.clear();
      res.emplace_back(v[st], v[i]);
    }
    else if (tesize == mx)
      res.emplace_back(v[st], v[i]);
    while (i - st >= 2)
    {
      auto te2 = vec(v[st + 1], v[i]);
      if (tesize < te2.size())
      {
        tesize = te2.size();
        st++;
        if (te2.size() > mx)
        {
          mx = te2.size();
          res.clear();
          res.emplace_back(v[st], v[i]);
        }
        else if (te2.size() == mx)
          res.emplace_back(v[st], v[i]);
      }
      else
        break;
    }
  }
  return res;
}

int main()
{
  //凸包http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=jp
  /* {
  ll n ;
  cin >> n ;
  vector<point> v,ans;
  rep(i,n){
    double x , y ;
    cin >> x >> y ;
    v.push_back({x,y});
  }
  ans=convex_hull(v);
  cout << ans.size() << endl;
  //以下は下（同じなら左）の点から反時計回りに出力する処理
  double mi=INF;
  rep(i,ans.size()){
    mi=min(mi,ans[i].y);
  }
  ll num;
  rep(i,ans.size()){
    if(ans[ans.size()-1-i].y==mi){num=i;break;}
  }
  if(mi==ans[0].y){
    cout << ans[0].x <<" " << ans[0].y << endl;
    rep(i,ans.size()-1)cout << ans[ans.size()-1-i].x <<" " << ans[ans.size()-1-i].y << endl;
    return 0;
  }
  for (ll i = num; i < ans.size(); i++)cout << ans[ans.size()-1-i].x <<" " << ans[ans.size()-1-i].y << endl;
  rep(i,num)cout << ans[ans.size()-1-i].x <<" " << ans[ans.size()-1-i].y << endl;
} */
  //凸包後の最遠点対http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B&lang=jp
  /* {
  ll n ;
  cin >> n ;
  vector<point> v;
  rep(i,n){
    double x , y ;
    cin >> x >> y ;
    v.push_back({x,y});
  }
  auto ans=convex_diameter(v);
  auto an=vec(ans[0].first,ans[0].second);
  cout<<fixed<<setprecision(12)<< an.size() <<endl;
} */

  return 0;
}
