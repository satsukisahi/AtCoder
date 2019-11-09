#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;
int num[2010][2010]={};

struct edge {
    int x,y;
    char c;
};
vector<edge> ta;
int main()
{ 
ll n,k;
cin >> n>>k; 
for (int i = 0; i < n; i++) {
    int x, y;
    char D;
    cin >> x >> y >> D;
    x=x%(2*k);
    y=y%(2*k);
    if(y>=k){
        x=(x+k)%(2*k);
        y=y-k;
    }
    if(D=='W'){
        x=(x+k)%(2*k);
    }
    ta.push_back({ x,y,D });
}



rep(i,n){
    num[ta[i].y][ta[i].x]++;
    num[ta[i].y+k][(ta[i].x+k)%(2*k)]++;
}
rep(i,2*k)rep1(j,2*k){
    num[i][j]+=num[i][j-1];
}
rep1(i,2*k)rep(j,2*k){
    num[i][j]+=num[i-1][j];
}
ll temp;

rep(i,k)rep(j,k){
    ll p=0,q=0,r=0;
    if(i!=0&&j!=0)r=num[i-1][j-1];
    if(i!=0)p=num[i-1][j+k-1];
    if(j!=0)q=num[i+k-1][j-1];
    temp=num[i+k-1][j+k-1]+r-p-q;
    ans=max(ans,max(temp,n-temp));
}

/* for (int i = 0; i < 2*k; ++i){
for (int j = 0; j < 2*k; ++j) {
    cout << num[i][j] << " ";
}cout  << endl;} */
cout << ans << endl;
return 0;
} 