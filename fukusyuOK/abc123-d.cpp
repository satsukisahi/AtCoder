#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
vector<ll> ans;
ll dp[0][0];

int main()
{
ll x,y,z,k;

cin >> x>>y>>z>>k;
ll tabx[x]={};
rep(i,x) {
    cin >> tabx[i];
}
ll taby[y]={};
rep(i,y) {
    cin >> taby[i];
}
ll tabz[z]={};
rep(i,z) {
    cin >> tabz[i];
}
/* sort(tabx, tabx + x);
sort(taby, taby + y);
sort(tabz, tabz + z);
 */
ll sum[x*y];
rep(i,x)rep(j,y){
    sum[i*y+j]=tabx[i]+taby[j];
}
sort(sum, sum + x*y, greater<ll>());
ll kk=k;
if(k>x*y){
    kk=x*y;
}
rep(i,kk)rep(j,y){
    ans.push_back(sum[i]+tabz[j]);
}

sort(ans.rbegin(), ans.rend());
rep(i,k){
cout << ans[i]<< endl;
}

return 0;
}



