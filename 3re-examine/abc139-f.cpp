#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans = 0;
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
bool cmp(const point &a, const point &b)
{
  return a.val < b.val;
}
//ベクトルabとベクトルbcにおけるbcに対して時計回りの角cba
double arg(vec a,vec b){
  if(a.x*b.y-a.y*b.x>0)return acos((-a.x*b.x-a.y*b.y)/(a.size()*b.size()))*(-180)/pi +360;
  else return acos((-a.x*b.x-a.y*b.y)/(a.size()*b.size()))*180/pi;
}
int main()
{
ll n ;
cin >> n ;
vector<point> v;
rep(i,n){
  double x , y ;
  cin >> x >> y ;
  if(x==0&&y==0)v.emplace_back(x,y,0);
  else v.emplace_back(x,y,arg(vec(-1,0),vec(x,y)));
}
auto mod = [&](ll modx){modx%=n;modx+=n;modx%=n;return modx;};
sort(v.begin(),v.end(),cmp);
rep(i,n)rep(j,n)
{
  double x=0,y=0;
  for (ll k = i; k < j+i+1; k++)
  {
    x+=v[mod(k)].x;
    y+=v[mod(k)].y;
  }
  ans=max(ans,sqrt(x*x+y*y));
}

cout<<fixed<<setprecision(13)<<ans<<endl;

return 0;
}
