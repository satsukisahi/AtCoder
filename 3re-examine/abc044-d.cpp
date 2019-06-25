#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = -1;

ll solve(ll b,ll n){
    if(n<b)return n;
    else return solve(b,n/b)+n%b;
}

int main()
{
ll n,s;
cin >> n>>s;
if(n==s){
    cout << n+1 << endl;
    return 0;
}
rep(i,sqrt(n)){
    if(solve(i+2,n)==s){
        cout << i+2 << endl;
        return 0;
    }
}
rep(i,sqrt(n)){
    if(s-i-1<0)break;
    if((n-s+i+1)%(i+1)==0&&(s-i-1)<((n-s+i+1)/(i+1))){
        ans=(n-s+i+1)/(i+1);
        //cout << ans <<" "<<i <<endl;
    }
    
}
cout << ans << endl;
return 0;
}
