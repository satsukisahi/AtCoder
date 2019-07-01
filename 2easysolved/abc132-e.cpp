#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m;
cin >> n>>m;
vector<ll> G[n];
rep(i,m){
    ll a,b;
    cin >> a>>b;
    G[a-1].push_back(b-1);
    }
ll s,t;
cin >> s>>t;
s--;t--;

queue<pair<int, int>> q;
ll info[n][3]={};
q.push({s,0});

while(!q.empty()){
    pair<int, int> p = q.front();
    q.pop();
    rep(i,G[p.first].size()){
        if(info[G[p.first][i]][(p.second+1)%3]==0){
            info[G[p.first][i]][(p.second+1)%3]=p.second+1;
            q.push({G[p.first][i],p.second+1});
        }
    }
}
if(info[t][0]==0)cout << -1 << endl;
else cout << info[t][0]/3 << endl;
return 0;
}
