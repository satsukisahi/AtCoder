#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll nn[10]={};
ll m=n;
rep(i,10){
    nn[i]=m%10;
    m/=10;
}
ll rec=10;
rep(i,10){
    if(nn[i]==0) ans+=(n/rec)*rec/10;
    else if(nn[i]==1) ans+=(n/rec)*rec/10+n%(rec/10)+1;
    else ans+=(n/rec+1)*rec/10;
    rec*=10;
}

cout << ans << endl;
return 0;
}
