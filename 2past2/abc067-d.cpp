#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
vector<ll> v[n];
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
}
ll ge[n]={};
ge[0]=1;
ge[n-1]=2;
queue<ll> f;
queue<ll> s;
ll ff=1 ,ss=1;
f.push(0);
s.push(n-1);
while(ff+ss<n){
    ll fs=f.size();
    ll sss=s.size();
    rep(i,fs){
        ll re;
        re=f.front();
        f.pop();
        rep(j,v[re].size()){
            if(ge[v[re][j]]==0){
                ge[v[re][j]]=1;
                ff++;
                f.push(v[re][j]);
                //cout << v[re][j] << endl;
            }
        }
    }
    rep(i,sss){
        ll re;
        re=s.front();
        s.pop();
        rep(j,v[re].size()){
            if(ge[v[re][j]]==0){
                ge[v[re][j]]=2;
                ss++;
                s.push(v[re][j]);
                //cout << v[re][j] << endl;
            }
        }
    }
    
}
if(ff>ss)cout << "Fennec" << endl;
else cout << "Snuke" << endl;

return 0;
}