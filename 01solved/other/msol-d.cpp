#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
set<ll> G[n];
ll t[n] = {};
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].insert(b-1);
    G[b-1].insert(a-1);
}
ll sum=0;
rep(i,n){
    cin >> t[i];
    sum+=t[i];
}
ll an[n]={};
sort(t,t+n);
ans=sum-t[n-1];
//startきめる
vector<ll> str;

rep(i,n){
    if(G[i].size()==1){
        str.push_back(i);
    }
}
//操作開始
ll con=0;
ll con2=0;
ll see=str[con2];
con2++;
an[see]=t[con];
con++;



while(con<n){
    
//そこに数字を入れてよいか
ll too=*G[see].begin();
//cout << see+1<<" "<<too+1 <<" "<<G[too].size()<< endl;
if(G[too].size()<=2){
    bool aa=G[see].erase(too);
    bool a=G[too].erase(see);
    see=too;
    an[too]=t[con];
    con++;
    //cout << aa<<a<< endl;
}
else{
    bool aa=G[see].erase(too);
    bool a=G[too].erase(see);
    //cout << aa<<a << endl;
    see=str[con2];
    con2++;
    an[see]=t[con];
    con++;
}
}
cout << ans << endl;
rep(i,n){
    cout << an[i] << " ";
}
cout  << endl;
return 0;
}