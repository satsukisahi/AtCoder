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
ll t[n+1] = {};
rep(i, n)
{
    ll tt;
    cin >> tt;
    t[i+1]=tt+t[i];
}
vector<ll> v(4);

/* for (int i = 0; i < n+1; ++i) {
    cout << t[i] << " ";
}cout  << endl; */

ll ii;
for(ll i=2;i<=n-2;i++){
    ll mean1=t[i];
    auto itr = lower_bound(t,t+i+1, mean1/2);
    if(abs(t[itr - t]-t[i]+t[itr - t])>abs(t[itr - t-1]-t[i]+t[itr - t-1]))
    {v[0]=t[itr - t-1];v[1]=t[i]-t[itr - t-1];}
    else {v[0]=t[itr - t];v[1]=t[i]-t[itr - t];}

    ll mean2=t[n]-t[i];
    itr = lower_bound(t+i+1,t+n+1, mean2/2+t[i]);
    if(abs(t[itr - t]-t[i]-t[n]+t[itr - t])>abs(t[itr - t-1]-t[i]-t[n]+t[itr - t-1]))
    {v[2]=t[itr - t-1]-t[i];v[3]=t[n]-t[itr - t-1];}
    else {v[2]=t[itr - t]-t[i];v[3]=t[n]-t[itr - t];}

    /* for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }cout  << endl; */

    sort(v.begin(), v.end());
    ans=min(ans,v[3]-v[0]);
    if(ans<v[3]-v[0])ii=i;
}

cout << ans <<endl;
return 0;
}