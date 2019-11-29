#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const double INF = 9223372036854775807; //MAX 9223372036854775807
double ans = 922337203685477580;
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
double udl=INF,udr=-INF;
double lru=-INF,lrd=INF;
double lr[4]={INF,-INF,INF,-INF};
double ud[4]={INF,-INF,INF,-INF};
rep(i,n){
    double x=p[i].x,y=p[i].y;

    if(p[i].h=='U'||p[i].h=='D'){
        if(udl>x)udl=x;
        if(udr<x)udr=x;
    }
        if(p[i].h=='R'||p[i].h=='L'){
        if(lrd>y)lrd=y;
        if(lru<y)lru=y;
    }
    if(p[i].h=='R'&&lr[0]>x)lr[0]=x;
    if(p[i].h=='R'&&lr[1]<x)lr[1]=x;
    if(p[i].h=='L'&&lr[2]>x)lr[2]=x;
    if(p[i].h=='L'&&lr[3]<x)lr[3]=x;
    if(p[i].h=='U'&&ud[0]>y)ud[0]=y;
    if(p[i].h=='U'&&ud[1]<y)ud[1]=y;
    if(p[i].h=='D'&&ud[2]>y)ud[2]=y;
    if(p[i].h=='D'&&ud[3]<y)ud[3]=y;
}
vector<double> v;
v.push_back(0);
rep(i,4){
    if(abs(lr[i])!=INF&&udl!=INF)v.push_back(abs(lr[i]-udl));
    if(abs(lr[i])!=INF&&udr!=-INF)v.push_back(abs(lr[i]-udr));
    if(abs(ud[i])!=INF&&lru!=-INF)v.push_back(abs(ud[i]-lru));
    if(abs(ud[i])!=INF&&lrd!=INF)v.push_back(abs(ud[i]-lrd));
}
rep(i,2)rep(j,2){
    if(abs(lr[i])!=INF&&abs(lr[j+2])!=INF)v.push_back((double)abs(lr[i]-lr[j+2])/2);
    if(abs(ud[i])!=INF&&abs(ud[j+2])!=INF)v.push_back((double)abs(ud[i]-ud[j+2])/2);
}
double tim;
rep(i,v.size()){
    double val=solve(p,v[i]);
    if(ans>val){ans=val;tim=v[i];}
}

for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
}cout  << endl;

cout<<fixed<<setprecision(10)<<ans<<" "<<tim<<endl;
return 0;
}