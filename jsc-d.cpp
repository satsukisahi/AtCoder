#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double pi=3.1415926535897932;
struct point {
    double x,y;
    point() {}
    point(double x, double y) : x(x), y(y){};
};
struct vec {
    double x ,y ;
    vec() {}
    vec(point a, point b) : x(b.x-a.x), y(b.y-a.y)  {};
    double size(){return sqrt(x*x+y*y);};
};
double arg(vec a,vec b){
  if(a.x*b.y-a.y*b.x>0)return acos((-a.x*b.x-a.y*b.y)/(a.size()*b.size()))*(-180)/pi +360;
  else return acos((-a.x*b.x-a.y*b.y)/(a.size()*b.size()))*180/pi;
}

int main()
{
auto krag = [](double krx){double eps=1e-6;krx-=eps; if(krx>0)return (ll)krx+1LL;else return (ll)krx;};
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> b(n);
rep(i, n){
  cin >> b[i];
}
vector<ll> an;
vector<point> v,res;
rep(i,n){
  point p(i,b[i]);
  v.push_back(p);
}
res.push_back(v[0]);ll cut=0;

for(auto p:v){
  if(cut==0){cut=1;continue;}

  ll lower=0,upper=res.size()-1;
  ll x1,x2;
  while(true){
    if(upper-lower<=10){
      vector<ll> ko;
      for (ll i = lower; i <= upper; i++){
        ko.push_back(krag((double)(a[an.size()+1]-res[i].y)/(an.size()+1.0-res[i].x)));
      }
      sort(ko.rbegin(),ko.rend());
      an.push_back(an.size()==0 ? ko[0] : max(an.back(),ko[0]));
      break;
    }
    x1=(upper-lower)/3+lower;
    x2=((upper-lower)*2)/3+lower;
    if(((double)a[an.size()+1]-res[x1].y)/(an.size()+1.0-res[x1].x) <((double)a[an.size()+1]-res[x2].y)/(an.size()+1.0-res[x2].x))lower=x1;
    else upper=x2;
  }

  if(res.size()<2)res.push_back(p);
  else{
    while(arg(vec(res[res.size()-2],res[res.size()-1]),vec(res[res.size()-1],p))<179.9999999&&res.size()>=2)res.pop_back();
    res.push_back(p);
  }
}

for(auto aa:an)cout << aa << endl;
return 0;
}
