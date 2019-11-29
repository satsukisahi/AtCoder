#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = (1LL << 63) -1; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll t[n][2] = {};
rep(i, n){
    cin >> t[i][0]>> t[i][1];
}

ll lower=0,upper=INF;
ll seenow,oklowest;
bool ok2butan;
while(true){
seenow=(lower+upper)/2;
ok2butan=true;
vector<ll> v;
rep(i,n){
    v.push_back((seenow-t[i][0])/t[i][1]);
    if(seenow-t[i][0]<0)ok2butan=false;
}
sort(v.begin(),v.end());
rep(i,n){
    if(v[i]<i)ok2butan=false;
}


if(ok2butan){
    upper=seenow;
    if(upper==lower+1){oklowest=seenow;break;}
    }
else {
    lower=seenow;
    if(upper==lower+1){oklowest=seenow+1;break;}
    }
}

cout << oklowest<< endl;
return 0;
}
