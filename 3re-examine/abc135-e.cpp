#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll k,x,y;
cin >> k >>x>>y;
if(k%2==0&&abs(x+y)%2==1){
cout << -1 << endl;
return 0;
}
ll xx=1,yy=1;
if(x<0){x=-x;xx=-1;}
if(y<0){y=-y;yy=-1;}

vector<ll> vx,vy;
ll nowx=0,nowy=0;
ll zan=abs(x-nowx)+abs(y-nowy);
//assert(zan>=k*2||k%2==0);


while(zan>2*k || zan%2==1 ){
  if(nowx==x){
    nowy+=k;
  }
  else if(nowx+k<=x){
    nowx+=k;
  }
  else{
    nowy+=k-x+nowx;
    nowx=x;
  }
  zan=abs(x-nowx)+abs(y-nowy);
  if(zan==0){
    cout << 1 << endl;
    cout << x*xx << " " << y*yy << endl;
    return 0;
  }
  vx.push_back(nowx);
  vy.push_back(nowy);
}
if(nowy>y&&zan!=k){
  vx.push_back(nowx-k+zan/2);
  vy.push_back(nowy-zan/2);
}
else if(abs(x-nowx)>abs(y-nowy)&&zan!=k){
  vx.push_back(nowx+zan/2);
  vy.push_back(nowy-k+zan/2);
}
else if(abs(x-nowx)<=abs(y-nowy)&&zan!=k){
  vx.push_back(x+k-zan/2);
  vy.push_back(y-zan/2);
}
vx.push_back(x);
vy.push_back(y);


cout << vx.size() << endl;
rep(i,vx.size()){
cout << vx[i]*xx << " " << vy[i]*yy << endl;
}
return 0;
}
