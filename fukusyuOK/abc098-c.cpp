#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=10000000;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
string s;
cin>>s;

ll m=0;
ll an[n];
rep(i,n){
    if(s[i]=='E')m++;
}

if(s[0]=='W')an[0]=m;
else an[0]=m-1;
rep(i,n-1){
    if(s[i]=='W'&&s[i+1]=='W')an[i+1]=1+an[i];
    else if(s[i]=='E'&&s[i+1]=='E')an[i+1]=-1+an[i];
    else an[i+1]=an[i];
}
rep(i,n){
    ans=min(ans,an[i]);
}

cout << ans << endl;
return 0;
}



