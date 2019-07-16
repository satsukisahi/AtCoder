#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 1;

int main()
{
ll n,k;
cin >> n>>k;

ll up=n-k;
ll down=k-1;

ans+=up*down*6;
ans+=(n-1)*3;
double p=(double)ans/(n*n*n);

cout<<fixed<<setprecision(10)<<p<<endl;
return 0;
}
