#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{ 
ll n;
cin >> n; 
ll t[n]={};
rep(i,n) {
    cin >> t [i];
}
if(n==2){
    cout << max(t[0],t[1]) << endl;
    return 0;
}

sort(t,t+n);

vector<int> yaku;
double sqrtNum = sqrt(t[0]);
for (int i = 1; i <= sqrtNum; i++){
    if(t[0]%i==0){yaku.push_back(i);yaku.push_back(t[0]/i);}
}
sort(yaku.rbegin(), yaku.rend());
rep(i,yaku.size()){
    ll co=0;
    rep1(j,n){
        if(t[j]%yaku[i]==0)co++;
    }
    if(co==n-2||co==n-1){
        ans=yaku[i];
        break;
    }
}

swap(t[0],t[1]);
vector<int> yakua;
sqrtNum = sqrt(t[0]);
for (int i = 1; i <= sqrtNum; i++){
    if(t[0]%i==0){yakua.push_back(i);yakua.push_back(t[0]/i);}
}
sort(yakua.rbegin(), yakua.rend());
rep(i,yakua.size()){
    ll co=0;
    rep1(j,n){
        if(t[j]%yakua[i]==0)co++;
    }
    if(co==n-2||co==n-1){
        if(ans<yakua[i])ans=yakua[i];
        break;
    }
}

cout << ans << endl;
return 0;
} 