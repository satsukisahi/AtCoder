#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = -INF;

int main()
{
ll n,k;
cin >> n>>k;
ll v[n] = {};
rep(i, n)
{
    cin >> v[i];
}
ll maxa=k;
if(k>n)maxa=n;

for(ll i=0;i<=maxa;i++){
    rep(j,i+1){
        vector<ll> vv;
        rep(l,j){
            vv.push_back(v[l]);
           // cout << v[l] << " ";
        }
        rep(l,i-j){
            vv.push_back(v[n-l-1]);
            //cout << v[n-l-1] << " ";
        }
        sort(vv.rbegin(), vv.rend());
        rep(l,k-i){
            if(vv.size()>0&&vv[vv.size()-1]<0)vv.pop_back();
            else break;
        }
        ll sum=0;
        rep(l,vv.size()){
            sum+=vv[l];
        }
        ans=max(sum,ans);
        vv.clear();

    }
}

cout << ans << endl;
return 0;
}