#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;
bool judgeIentersected(double ax, double ay,double bx,double by,double cx,double cy,double dx,double dy) {
  double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

  return tc * td < 0 && ta * tb < 0;
}
int main()
{
double ax,ay,bx,by;
ll n;
cin >> ax>>ay>>bx>>by>>n;
double x[n] = {};
double y[n] = {};

rep(i, n){
    cin >> x[i] >> y[i];
}

rep(i,n-1){
    if(judgeIentersected(ax,ay,bx,by,x[i],y[i],x[i+1],y[i+1]))ans++;
}


cout << (ans+1)/2+1 << endl;
return 0;
}
