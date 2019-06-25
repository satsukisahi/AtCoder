#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
set<ll> G[100000];
set<ll> H[100000];

int main()
{
ll n;
cin >> n;

rep(i, n)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].insert(b-1);
    H[b-1].insert(a-1);
}
queue<ll> qx;
queue<ll> qy;
set<ll> x,y;
rep(i,100000){
    
    if(G[i].size()!=0){
        ll si=G[i].size();
        rep(j,si){
            ll itre=*G[i].begin();
            qy.push(itre);
            G[i].erase(itre);
            H[itre].erase(i);
            x.insert(i);
            y.insert(itre);
        }
    }
    while(!qx.empty()||!qy.empty()){
        if(!qy.empty()){
            ll qyy= qy.front();
            qy.pop();
            ll si=H[qyy].size();
            rep(j,si){
                ll itre=*H[qyy].begin();
                qx.push(itre);
                G[itre].erase(qyy);
                H[qyy].erase(itre);
                x.insert(itre);
                y.insert(qyy);
            }
        }
        if(!qx.empty()){
            ll qxx= qx.front();
            qx.pop();
            ll si=G[qxx].size();
            rep(j,si){
                ll itre=*G[qxx].begin();
                qy.push(itre);
                H[itre].erase(qxx);
                G[qxx].erase(itre);
                y.insert(itre);
                x.insert(qxx);
            }
        }
    }
    ans+=x.size()*y.size();
    x.clear();
    y.clear();
}


cout << ans-n << endl;
return 0;
}