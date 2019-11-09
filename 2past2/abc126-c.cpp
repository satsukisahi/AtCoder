#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
double ans = 0.0;

int main()
{
ll n,k;
cin >> n>>k;
rep(i,n){
    ll temp=i+1;
    double p=1/(double)n;
    while(temp<k){
        p=p*0.5;
        temp=temp*2;
    }
    ans+=p;
}

cout<<fixed<<setprecision(10)<<ans<<endl;
return 0;
}