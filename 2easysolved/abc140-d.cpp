  #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , k ;
cin >> n >> k ;
string s ;
cin >> s ;
vector<ll> v;
ll num=0;
rep(i,n-1){
  if(s[i]!=s[i+1])num++;
}
num-=k*2;
if(num<=0)ans=n-1;
else ans=n-num-1;

cout << ans << endl;
return 0;
}
