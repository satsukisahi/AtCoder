#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807

int main()
{
ll n;
cin >> n;
ll ans[n+1] = {};
ll t[n+1] = {};
rep(i, n){
    cin >> t[i+1];
}
for (ll i = n; i > 0; i--)
{
    ll ch=i;
    ll now=ch*2;
    ll sum=0;
    while(now<=n){
        sum+=ans[now];
        now+=ch;
    }
    if((sum%2)^t[i])ans[i]=1;
    else ans[i]=0;
}
ll m=0;
rep(i,n+1){
if(ans[i])m++;
}
cout << m << endl;
bool aaa=0; 
rep(i,n){
    if(ans[i+1]){
        if(aaa){cout << " ";}
        cout  <<i+1;
        aaa=1;
    }
}
if(aaa)cout <<  endl;
return 0;
}

