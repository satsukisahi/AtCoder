#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
ll bi[20]={};
ll max,sum,coun=0;
rep(i,20){
    if(((n>>i)&1LL)==1){
        bi[i]++;
        max=i;
        coun++;
    }
}
cout << max+1<<' '<< max*2+coun-1<< endl;
rep(i,max){
    cout << i+1<<' '<<i+2 <<' '<<'0'<< endl;
    cout << i+1<<' '<<i+2 << ' '<< (1<<i)<<endl;
}
sum=(1LL<<max);
rep(i,max){
    if(bi[i]==1){
        cout << i+1<<' '<<max+1 <<' '<<sum<< endl;
        sum+=(1LL<<(i));
    }
}
return 0;
}