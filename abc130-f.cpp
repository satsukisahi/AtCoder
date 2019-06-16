#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
double ans = 0;
struct point{ll x, y;char h;};
ll n;

double solve(point *p,double time){
    double xmax=-INF,xmin=INF,ymax=-INF,ymin=INF;
    rep(i,n){
        double x=p[i].x,y=p[i].y;
        if(p[i].h=='R')x+=time;
        if(p[i].h=='L')x-=time;
        if(p[i].h=='U')y+=time;
        if(p[i].h=='D')y-=time;
        if(xmax<x)xmax=x;
        if(ymax<y)ymax=y;
        if(xmin>x)xmin=x;
        if(ymin>y)ymin=y;
    }
return (xmax-xmin)*(ymax-ymin);

}

int main()
{

cin >> n;
ll t[n] = {};

point p[n];
rep(i, n){
    cin >> p[i].x>> p[i].y>> p[i].h;
}

double lower=0,upper=1000000000;
double x1,x2;

while(true){
    x1=(upper-lower)/3+lower;
    x2=(upper-lower)*2/3+lower;
    if(solve(p,x1)>solve(p,x2))lower=x1;
    else upper=x2;

    if(x2-x1<0.00000000001){
        ans=(x1+x2)/2;
        break;
    }
}

cout<<fixed<<setprecision(10)<<solve(p,ans)<<endl;
return 0;
}