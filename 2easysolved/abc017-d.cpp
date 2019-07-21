#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807

int main()
{
ll n,m;
cin >> n >> m ;
ll ans[n+1] = {};
ll t[n] = {};
bool see[m+1]={};
ll back=0;
ans[0]=1;
rep(i, n){
    cin >> t[i];
}
ll sum=1;

rep(i,n){
    if(!see[t[i]]){
        ans[i+1]=sum;
    }
    else {
        while(1){
            sum-=ans[back];
            sum=(sum+mo)%mo;
            see[t[back]]=0;
            if(t[back]==t[i]){back++;break;}
            back++;
        }
        ans[i+1]=sum;
    }
    sum+=ans[i+1];
    sum%=mo;
    see[t[i]]=1;
    ans[i+1]=(ans[i+1]+mo)%mo;

}


cout << ans[n] << endl;
return 0;
}
