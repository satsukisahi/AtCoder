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
ll n,m;
cin >> n >>m; 
ll table[n]={};
rep(i,n) {
    cin >> table [i];
}
ll tab[n+1];
tab[0]=0;
rep(i,n){
    tab[i+1]=(tab[i]+table[i])%m;
}
map<ll,ll> mod{};
rep(i,n+1){
    mod[tab[i]]++;
}

for (auto i = mod.begin(); i != mod.end(); ++i) {
    ll lll=i->second;
    ans+=lll*(lll-1)/2;
}
cout << ans << endl;
return 0;
} 