#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
ll b=0,c=0;
rep(i,n){
  if(a[i]%4==0)b++;
  if(a[i]%2==1)c++;
}
bool ok=1;
if(b==0&&c>0)ok=0;
else if(b<c-1)ok=0;
else if(b==c-1 && n!=b+c)ok=0;
cout << (ok? "Yes" :"No") << endl;
return 0;
}