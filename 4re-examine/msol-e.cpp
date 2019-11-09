#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000003;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll mypow(ll a,ll b){
	ll res=1;
	a%=mo;
	while(b){
		if(b&1)
			res=res*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return res;
}
int main()
{
ll q;
cin >> q;
ll t[q][3] = {};
vector<ll> kaij;
kaij.push_back(1);
for(ll i = 1; i < mo*2; i++){
    kaij.push_back((kaij[i-1]*i)%mo);
}
rep(i, q)
{
    cin >> t[i][0]>>t[i][1]>>t[i][2];
}
rep(i,q){
    if(t[i][1]==0)ans=mypow(t[i][0],t[i][2]);
    else if(t[i][0]==0)ans=0;
    else{
        t[i][0]=t[i][0]*mypow(t[i][1],mo-2)%mo;
        ll y=t[i][0]+t[i][2]-1;
        if(y>=mo)ans=0;
        else ans=kaij[y]*mypow(t[i][1],t[i][2])*mypow(kaij[t[i][0]-1],mo-2);
    }
    cout << ans%mo << endl;
}


return 0;
}