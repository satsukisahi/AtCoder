#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
const double eps = 1e-10;

int main()
{
ll n;
cin >> n;
pair<ll,ll> t[n] = {};
rep(i, n){
    cin >> t[i].first >> t[i].second ;
}
ll sum = n*(n-1)*(n-2)/6;
ll cnt90 = 0, cnt = 0;
rep(i,n){
    vector<double> v;
    rep(j,n){
        if(i==j)continue;
        if(t[j].second-t[i].second<0)v.push_back(2*M_PI+atan2(t[j].second-t[i].second, t[j].first-t[i].first));
        else v.push_back(atan2(t[j].second-t[i].second, t[j].first-t[i].first));
    }
    sort(v.begin(),v.end());
    rep(j,v.size()){
        cnt90+=upper_bound(v.begin(),v.end(), v[j]+eps+M_PI/2)-lower_bound(v.begin(),v.end(), v[j]-eps+M_PI/2);
        cnt90+=upper_bound(v.begin(),v.end(), v[j]+eps+M_PI*3/2)-lower_bound(v.begin(),v.end(), v[j]-eps+M_PI*3/2);
        cnt+=upper_bound(v.begin(),v.end(), v[j]-eps+M_PI*3/2)-lower_bound(v.begin(),v.end(), v[j]+eps+M_PI/2);
    }
}

cout << sum-cnt-cnt90 << " " << cnt90 << " " << cnt << endl;
return 0;
}
