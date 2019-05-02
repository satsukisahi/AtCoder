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
ll h,w,d;
cin >> h>>w>>d; 
pair<ll, ll> t[h*w];
ll temp;
rep(i,h)rep(j,w) {
    cin >> temp;
    t[temp-1].first=j;
    t[temp-1].second=i;
}
ll q;
cin >> q; 
pair<ll, ll> p[q];
rep(i,q) {
    ll a,b;
    cin >> a>>b;
    p[i].first=a-1;
    p[i].second=b-1;
}
ll da[d][h*w/d+1]={};
rep(i,d)for(ll j=i+d;j<h*w;j+=d){
    da[i][j/d]=da[i][j/d-1]+abs(t[j].first-t[j-d].first)+abs(t[j].second-t[j-d].second);
}
/* for (int i = 0; i < 2; ++i){
for (int j = 0; j < 5; ++j) {
    cout << da[i][j] << " ";
}cout  << endl;} */
rep(i,q){
    cout << da[p[i].second%d][p[i].second/d]-da[p[i].first%d][p[i].first/d] << endl;
}

return 0;
} 