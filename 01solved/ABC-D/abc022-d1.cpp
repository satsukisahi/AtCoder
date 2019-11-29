#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
double pi=3.1415926535897932;

struct point {
    double x,y,val;
    point() {}
    point(double x, double y, double val) : x(x), y(y), val(val) {};
    point(double x, double y) : x(x), y(y), val(0) {};
};
struct vec {
    double x ,y ;
    vec() {}
    vec(double x, double y) : x(x), y(y)  {};
    vec(point a, point b) : x(b.x-a.x), y(b.y-a.y)  {};
    double size(){return sqrt(x*x+y*y);};
};
//xの昇順で同じときyの昇順
bool cmp(const point &a, const point &b)
{
  if(a.x == b.x) return a.y < b.y;
  else return a.x < b.x;
}
//ベクトルabとベクトルbcにおけるbcに対して時計回りの角cba
double arg(vec a,vec b){
  if(a.x*b.y-a.y*b.x>0)return acos((-a.x*b.x-a.y*b.y)/(a.size()*b.size()))*(-180)/pi +360;
  else return acos((-a.x*b.x-a.y*b.y)/(a.size()*b.size()))*180/pi;
}
//線分abとcdの交差判定
bool judgeIentersected(point a,point b, point c,point d) {
  double ta = (c.x - d.x) * (a.y - c.y) + (c.y - d.y) * (c.x - a.x);
  double tb = (c.x - d.x) * (b.y - c.y) + (c.y - d.y) * (c.x - b.x);
  double tc = (a.x - b.x) * (c.y - a.y) + (a.y - b.y) * (a.x - c.x);
  double td = (a.x - b.x) * (d.y - a.y) + (a.y - b.y) * (a.x - d.x);
  return tc * td < 0 && ta * tb < 0;
  //return tc * td <= 0 && ta * tb <= 0; // 端点を含む場合
}
//凸包　左（同じなら下）から時計回りに出力
vector<point> convex_hull(vector<point>& v){
  sort(v.begin(),v.end(),cmp);
  vector<point> res,res2;
  for(auto p:v){
    if(res.size()<2)res.push_back(p);
    else{
      while(arg(vec(res[res.size()-2],res[res.size()-1]),vec(res[res.size()-1],p))>180.00001&&res.size()>=2)res.pop_back();
      res.push_back(p);
    }
  }
  for(auto p:v){
    if(res2.size()<2)res2.push_back(p);
    else{
      while(arg(vec(res2[res2.size()-2],res2[res2.size()-1]),vec(res2[res2.size()-1],p))<179.99999&&res2.size()>=2)res2.pop_back();
      res2.push_back(p);
    }
  }
  rep(i,res2.size()-2){
    res.push_back(res2[res2.size()-i-2]);
  }
  return res;
}
//凸包における最遠点対
vector<pair<point,point>> convex_diameter(vector<point>& v){
  ll st=0;
  double mx=0;
  vector<pair<point,point>> res;
  for(ll i=1;i<v.size();i++){
    auto te=vec(v[st],v[i]);
    double tesize=te.size();
    if(tesize>mx){
      mx=tesize;
      res.clear();
      res.emplace_back(v[st],v[i]);
    }
    else if(tesize==mx)res.emplace_back(v[st],v[i]);
    while(i-st>=2){
      auto te2=vec(v[st+1],v[i]);
      if(tesize<te2.size()){
        tesize=te2.size();
        st++;
        if(te2.size()>mx){
          mx=te2.size();
          res.clear();
          res.emplace_back(v[st],v[i]);
        }
        else if(te2.size()==mx)res.emplace_back(v[st],v[i]);
      }
      else break;
    }
  }
  return res;
}

int main()
{
  ll n ;
  cin >> n ;
  vector<point> v;
  rep(i,n){
    double x , y ;
    cin >> x >> y ;
    v.push_back({x,y});
  }
  auto va=convex_hull(v);
  auto ans=convex_diameter(va);
  auto an=vec(ans[0].first,ans[0].second);
  vector<point> vv;
  rep(i,n){
    double x , y ;
    cin >> x >> y ;
    vv.push_back({x,y});
  }
  auto vb=convex_hull(vv);
  auto anss=convex_diameter(vb);
  auto ann=vec(anss[0].first,anss[0].second);
  cout<<fixed<<setprecision(12)<< ann.size()/an.size() <<endl;

  return 0;
}
