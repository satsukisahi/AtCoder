#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


//線分abとcdの交差判定
bool judgeIentersected(double ax, double ay,double bx,double by,double cx,double cy,double dx,double dy) {
  double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

  return tc * td < 0 && ta * tb < 0;
  //return tc * td <= 0 && ta * tb <= 0; // 端点を含む場合
}

int main()
{


return 0;
}
