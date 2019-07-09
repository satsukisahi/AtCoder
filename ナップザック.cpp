#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
ll dp[201][200002]={};

int main()
{
ll n,w;
cin >> n >> w ;
pair<ll,ll> t[n] = {};
ll wmax=0;
rep(i, n){
    cin >> t[i].second >> t[i].first;
    wmax=max(wmax,t[i].first);
}
if(n<=30){
    vector<pair<ll,ll>> v1;
    vector<pair<ll,ll>> v2;

    rep(i,1<<(n/2)){
        pair<ll,ll> p;
        rep(j,n/2){
            if(i>>j&1){
                p.first+=t[j].first;
                p.second+=t[j].second;
            }
        }
        v1.push_back(p);
    }
    rep(i,1<<(n-n/2)){
        pair<ll,ll> p;
        rep(j,n-n/2){
            if(i>>j&1){
                p.first+=t[n/2+j].first;
                p.second+=t[n/2+j].second;
            }
        }
        v2.push_back(p);
    }

    sort(v1.begin(),v1.end());
    ll v1mx=0;
    rep(i,v1.size()){
        v1mx=max(v1mx,v1[i].second);
        v1[i].second=max(v1mx,v1[i].second);
    }
    rep(i,v2.size()){
        if(v2[i].first>w)continue;
        pair<ll,ll> pp={w-v2[i].first,INF};
        auto itr=upper_bound(v1.begin(),v1.end(), pp);
        itr--;
        pair<ll,ll> p=*itr;
        ans=max(ans,p.second+v2[i].second);

    }

}

else if(wmax<=1000){
    rep(i,n){
        rep(j,200002){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j+t[i].first<=w)
            dp[i+1][j+t[i].first]=max(dp[i+1][j+t[i].first],dp[i][j]+t[i].second);
            
        }
    }
    rep(i,200002){
        ans=max(ans,dp[n][i]);
}
}

else{
    rep(i,n+1)rep(j,200000){
        dp[i][j]=INF;
    }
    rep(i,n){
        rep(j,200000){
            if(j==0){
                dp[i+1][t[i].second]=min(dp[i+1][t[i].second],t[i].first);
            }
            else if(dp[i][j]!=INF){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                dp[i+1][j+t[i].second]=min(dp[i+1][j+t[i].second],dp[i][j]+t[i].first);
            }
        }
    }
    rep(i,n)rep(j,200000){
        if(dp[i+1][j]<=w&&dp[i+1][j]>0)ans=max(ans,j);
    }

}

cout << ans << endl;
return 0;
}
