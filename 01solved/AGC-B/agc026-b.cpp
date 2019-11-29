#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll t ;
cin >> t ;
ll v[t][4]={};
rep(i,t){
  cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] ;
}
rep(i,t){
  ll a=v[i][0] , b=v[i][1] , c=v[i][2] , d=v[i][3] ;
  if(b>d||a<b){cout << "No" << endl;continue;}
  if(b<=c+1){cout << "Yes" << endl;continue;}
  ll e=__gcd(b,d);
  ll f=a%b;
  if(f>c){cout << "No" << endl;continue;}
  if(b-e<=c){cout << "Yes" << endl;continue;}
  else cout << "No" << endl;
}


return 0;
}
