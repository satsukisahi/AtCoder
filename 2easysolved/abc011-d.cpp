#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
long double ans = 0;

int main()
{
ll n,d,x,y;
cin >> n>>d>>x>>y;
if(x!=(x/d) *d||y!=(y/d) *d){
    cout << ans << endl;
    return 0;
}
x=x/d;
x=abs(x);
y=y/d;
y=abs(y);
if((x+y)%2 != n%2 ){
    cout << ans << endl;
    return 0;
}
ll a=(n-x-y)/2;
rep(i,a+1){
    long double sum=1;
    long double kai=n;
    ll k[4]={i,a-i,i+x,a-i+y};
    rep(j,4){
        rep(l,k[j]){
            sum*=(long double)kai/(((l+1)*4));
            kai--;
        }
    }
    ans+=sum;
}

cout<<setprecision(15)<<ans<<endl;
return 0;
}
