#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll n;
cin >> n;

rep(i, n)
{
  ll a,b,ans=0;
	cin >> a>>b;
	if(a*b==1){cout << 0 << endl;continue;}
	if(a<=b)swap(a,b);
	ans+=(ll)sqrt(a*b);
	if((ll)sqrt(a*b)*(ll)sqrt(a*b)==a*b){ans--;}
	//cout << ans<<" ";

	ll an=((a*b)/ans);
	if(an*ans==a*b)an--;

	if(an==b)an--;
	if((an-1)*(ans+1)>=a*b)an--;

	an--;
	if(an>=b)an--;
	ans+=an;

	//cout << an <<" ";
	cout << ans << endl;
}


return 0;
}