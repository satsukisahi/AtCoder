#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n;
cin >> n;
if(n==1){
    cout << 1 << endl;
    return 0;
}
vector<pair<int, int> > pa(n);
rep(i, n){
    ll a,b;
    cin >> a>> b;
    pa[i]=make_pair(a,b );
}
sort(pa.begin(),pa.end());

for(ll i=0;i<n-1;i++)for(ll j=i+1;j<n;j++){
    ll p,q;
    p=pa[j].first-pa[i].first;
    q=pa[j].second-pa[i].second;
    bool ch[n]={};
    
    ll an=0;
    rep(k,n){
        if(ch[k]==0){
            ch[k]=1;
            an++;
            ll seex=pa[k].first;
            ll seey=pa[k].second;
            for(ll l=k+1;l<n;l++){
                if(seex+p==pa[l].first&&seey+q==pa[l].second){
                    ch[l]=1;
                    seex+=p;
                    seey+=q;
                }
            }
        }
    }
    ans=min(ans,an);
    

}

cout << ans << endl;
return 0;
}
