#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll H , W , h , w ;
cin >> H >> W >> h >> w ;
if(H%h==0&&W%w==0){
  cout << "No" << endl;
  return 0;
}
cout << "Yes" << endl;
if(W%w!=0){
  rep(i,H){
    rep(j,W){
      if((j+1)%w)cout << 100000 << " ";
      else cout << -100000*(w-1)-1 << " ";
    }
    cout << endl;
  } 
}
else{
  rep(i,H){
    rep(j,W){
      if((i+1)%h)cout << 100000 << " ";
      else cout << -100000*(h-1)-1 << " ";
    }
    cout << endl;
  } 
}
}