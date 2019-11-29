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
string s;
cin >> s;

int len=(int)(s.length());

ll kai1=0;
rep(i,len){
    if(i%2==0){
        if(s[i]=='0')kai1++;
    }
    else{
        if(s[i]=='1')kai1++;
    }
}

ans=min(kai1,len-kai1);
cout << ans << endl;
return 0;
}



