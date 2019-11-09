#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807


int main()
{
ll n,k;
scanf("%lld%lld", &n, &k);
ll t[n] = {};
rep(i, n){
    scanf("%d", &t[i]);
}
pair<ll,ll> to[n];
{vector<ll> bac(200001,0);
vector<ll> flo(200001,-1);
rep(i,n){
    to[n-i-1].first=bac[t[n-i-1]];
    bac[t[n-i-1]]=n-i-1;
}
rep(i,n){
    if(flo[t[i]]==-1)flo[t[i]]=i;
}
rep(i,n){
    if(to[i].first==0){to[i].first=flo[t[i]];to[i].second=1;}
    if(to[i].first==n-1)to[i].second=1;
    to[i].first=to[i].first+1;
    if(i==n-1&&to[i].first==n)to[i].second++;
    to[i].first%=n;
}
}
vector<ll> v;
set<ll> st;
v.push_back(0);
st.insert(0);
ll sy=0;
while(1){
    ll too=to[v.back()].first;
    auto r = st.insert(too);
    if(r.second){sy+=to[v.back()].second;v.push_back(too);}
    else {sy+=to[v.back()].second;break;}
}
k%=sy;
if(k==0)return 0;
ll str=0;
ll now=0;
vector<ll> ans;
while(1){
    now+=to[str].second;
    if(k>now)str=to[str].first;
    else{
        
        for (ll i = str; i < n; i++)
        {
            ans.push_back(t[i]);
        }
        break;
    }
}

vector<ll> anss;
set<ll> stt;
rep(i,ans.size()){
    auto r =stt.insert(ans[i]);
    if(r.second)anss.push_back(ans[i]);
    else{
        while(1){
            if(ans[i]==anss.back())break;
            stt.erase(anss.back());
            anss.pop_back();
        }
        stt.erase(anss.back());
        anss.pop_back();
    }
}



for (int aa : anss) printf("%d ", aa);
return 0;
}
