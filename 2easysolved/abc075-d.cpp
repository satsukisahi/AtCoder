#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 	9223372036854775807;
ll ans = INF;

int main()
{
ll n,k;
cin >> n>>k;
pair<ll, ll> p[n];
pair<ll, ll> y[n];
rep(i, n)
{
    cin >> p[i].first>>p[i].second;
    y[i].first=p[i].second;
    y[i].second=p[i].first;
}
sort(p,p+n);
sort(y,y+n);
rep(i,n-1)for (ll j = i+1; j < (ll)(n); j++){
    ll left=p[i].first,right=p[j].first;
    rep(l,n){
        if(y[l].second>=left&&y[l].second<=right){
            ll count=1;
            for (ll m = l+1; m < (ll)(n); m++){
                if(y[m].second>=left&&y[m].second<=right)count++;
                if(count>=k){
                    ans=min(ans,(-left+right)*(y[m].first-y[l].first));
                    break;
                }
            }
        }
    }
}

cout << ans << endl;
return 0;
}