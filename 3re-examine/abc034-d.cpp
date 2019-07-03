#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
double ans = 0;

int main()
{
ll n,k;
cin >> n>>k;
pair<ll, ll> p[n];
rep(i, n){
    cin >> p[i].first>>p[i].second;
}

double lower=0,upper=100;
double seenow;
rep(ii,100){
seenow=(lower+upper)/2;

vector<double> v;
rep(j,n){
    v.push_back(p[j].first*(p[j].second-seenow));
}
sort(v.rbegin(), v.rend());
double sum=0;
rep(j,k){
    sum+=v[j];
}
if(sum>0)lower=seenow;
else upper=seenow;
v.clear();
}

ans=seenow;
cout<<fixed<<setprecision(10)<<ans<<endl;
return 0;
}
