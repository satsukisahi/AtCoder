#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 1;

int main()
{
ll n,k;
cin >> n >> k ;
vector<ll> G[n];
bool see[n]={};
ll info[n]={};
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1); 
}
info[0]=k;
see[0]=1;
bool syo=1;
queue<ll> q;
q.push(0);
while(!q.empty()){
    ll a=q.front();
    q.pop();
    see[a]=1;
    ll cnt=0;
    rep(i,G[a].size()){
        if(see[G[a][i]])continue;
        if(syo){
            info[G[a][i]]=k-1-cnt;
        }
        else {
            info[G[a][i]]=k-2-cnt;
        }
        cnt++;
        q.push(G[a][i]);
    }
    syo=0;
}
rep(i,n){
    if(info[i]<1){
        ans=0;
        break;
    }
    ans*=info[i];
    ans%=mo;
}

cout << ans << endl;
return 0;
}
