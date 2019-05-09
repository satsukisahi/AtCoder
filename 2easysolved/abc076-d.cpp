#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
double ans = 0;

int main()
{
ll n;
cin >> n;
ll t[n] = {};
ll v[n] = {};
double co[50010]={};
double ma[50010]={};
double mi[50010]={};
rep(i, n)
{
    cin >> t[i];
}
rep(i, n)
{
    cin >> v[i];
}
co[0]=0;
ll a=t[0],b=0;
rep1(i,50010){
    if(i<a*2)co[i]=v[b];
    else {
        b++;
        if(b>=n){co[i]=0;break;}
        else co[i]=min(v[b],v[b-1]);
        a+=t[b];
    }
}
rep1(i,50010){
    ma[i]=min(ma[i-1]+0.5,co[i]);
}
for (ll i = 50008; i >=0; i--){
    mi[i]=min(mi[i+1]+0.5,co[i]);
}
rep1(i,50009){
    //ans+=((double)min(ma[i],mi[i])+(double)min(ma[i-1],mi[i-1]))/2.0;
    ans+=(double)min(ma[i],mi[i]);
}

double answer=ans/2.0;

/* for (int i = 0; i <60; ++i) {
    cout << i<<" "<<co[i] << " "<<ma[i]<< " "<<mi[i]<< " "<<min(ma[i],mi[i])<< endl;
} */



cout <<   answer << endl;
return 0;
}