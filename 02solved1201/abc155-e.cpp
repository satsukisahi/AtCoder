#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
string n ;
cin >> n ;
ll k=0;
for (ll i = n.size()-1; i >= 0; i--)
{
  if(n[i]-'0'+k>=6){ans+=10-(n[i]-'0'+k);k=1;}
  if(n[i]-'0'+k<=4){ans+=(n[i]-'0')+k;k=0;}
  if(n[i]-'0'+k==5){
    if(i!=0&&n[i-1]-'0'>=5){ans+=5;k=1;}
    else {ans+=5;k=0;}
  }
}

cout << ans+k << endl;
return 0;
}