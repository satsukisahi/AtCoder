#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=9999999;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
string s;
cin >> s;
ll bl=0;
ll ren=0;
ll ten=0;
ll bll=0;
bool a=0;
rep(i,n){
    if(s[i]!='#')ten++;
    if(s[i]=='#')bll++;
}
ll nowten=0;
ll temp;
rep(i,n-1){
    if(s[i]!='#')nowten++;
    if(s[i]=='#'){ren++;bl++;}
    if(s[i]=='#'&&s[i+1]!='#'){
        temp=ten-nowten+bl-ren;
        if(temp>bll)temp=bll;
        if(ans>temp){ans=temp;}
        ren=0;}
}
if(ans==9999999)ans=0;
cout << ans << endl;
return 0;
}






