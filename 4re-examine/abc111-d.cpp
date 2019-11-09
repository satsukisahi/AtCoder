#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
ll w[n][2];
bool pa;
rep(i,n){
  ll x , y ;
  cin >> x >> y ;
  if(i==0)pa=(x+y+30000000000)%2;
  if((x+y+30000000000)%2!=pa){
    cout << -1 << endl;
    return 0;
  }
  if(!pa)x--;
  w[i][0]=x;
  w[i][1]=y;
}

if(pa)cout << 35 << endl;
else cout << 36 << endl;
rep(i,35){
  cout << (1LL<<(35-i-1)) << " ";
}
if(!pa)cout << 1 << " ";
cout << endl;
string ans[n]={};
rep(i,n){
  ll u=w[i][0]+w[i][1],v=w[i][0]-w[i][1];
  ll xx=0,yy=0;
  rep(j,35){
    if(u-xx>=0&&v-yy>=0){xx+=(1LL<<(35-j-1));yy+=(1LL<<(35-j-1));ans[i]+="R";}
    else if(u-xx<0&&v-yy<0){xx-=(1LL<<(35-j-1));yy-=(1LL<<(35-j-1));ans[i]+="L";}
    else if(u-xx>=0&&v-yy<0){xx+=(1LL<<(35-j-1));yy-=(1LL<<(35-j-1));ans[i]+="U";}
    else {xx-=(1LL<<(35-j-1));yy+=(1LL<<(35-j-1));ans[i]+="D";}
  }
  //if(xx==u&&yy==v)cout << "ok" << endl;
}
rep(i,n){
  if(pa)cout << ans[i] << endl;
  else cout << ans[i]+"R" << endl;
  
}
return 0;
}
