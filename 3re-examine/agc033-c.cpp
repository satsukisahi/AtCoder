#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;
vector<ll> G[200010];
int d[200010];

void dist(int v){
    rep(i,G[v].size()){
        if(d[G[v][i]]==INF){
            d[G[v][i]]=d[v]+1;
            dist(G[v][i]);
        }
    }
}

int main()
{ 
ll n;
cin >> n; 
for (int i = 0; i < n-1; i++) {
    int L, R;
    cin >> L >> R ;
    L--; R--;
    G[L].push_back(R);
    G[R].push_back(L);
}

rep(i,n){
    d[i]=INF;
}
d[0]=0;
dist(0);
ll max=0,x;
rep(i,n){
    if(max<d[i]){
        max=d[i];
        x=i;
    }
}

rep(i,n){
    d[i]=INF;
}
d[x]=0;
dist(x);
max=0;
rep(i,n){
    if(max<d[i]){
        max=d[i];
        x=i;
    }
}
max++;
//cout << max << endl;
if(max%3==2)cout << "Second" << endl;
else cout << "First" << endl;

/* for (int i = 0; i < n; ++i) {
    cout << d[i] << " ";
}cout  << endl; */


return 0;
} 