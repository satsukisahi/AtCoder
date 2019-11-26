#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
ll a=1,t=64-__builtin_clzll(n);
rep(i,t-1)a=(a<<1)+((i%2)^(t%2)?1:0);
cout << ((a>n)^(t%2)?"Aoki":"Takahashi") << endl;
return 0;
}