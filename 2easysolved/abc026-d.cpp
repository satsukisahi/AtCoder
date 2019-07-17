#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
double ans = 0;
ll a,b,c;
double eps = 1e-10;

double f(double t){
    return a*t+b*sin(c*t*M_PI)-100;
}

int main()
{
cin >> a>>b>>c;
ll d;
rep(i,200){
    if(f(i)*f(i+1)<=0){
        d=i;break;}
}

double upp=d,dow=d+1;
if(f(d)<f(d+1)){swap(upp,dow);}

while(fabs(upp-dow)>eps){
    //cout << upp<<" "<<dow <<" " << f(upp)<<" "<<f(dow)<< endl;

    double see=(upp+dow)/2;
    if(f(see)>0)upp=see;
    else dow=see;
}

ans=(upp+dow)/2;
cout<<fixed<<setprecision(10)<<ans<<endl;
return 0;
}
