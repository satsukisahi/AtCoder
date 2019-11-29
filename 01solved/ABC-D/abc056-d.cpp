#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans;

int main()
{
ll n,k;
cin >> n>>k;
ll t[n] = {};
ll sum=0;
ll nn=0;
rep(i, n)
{
    cin >> t[i];
    sum+=t[i];
    if(t[i]<k)nn++;
}
if(sum<k){
    cout << n<< endl;
    return 0;
}
if(nn==0){
    cout << 0<< endl;
    return 0;
}
sort(t,t+n);
int lower=0,upper=nn;
int seenow=lower,oklowest;
bool ok2butan;
vector<bool> vv(k, false);

vv[0]=true;
rep(i,nn){
    if(i==seenow)continue;
    rep(j,k){
        if(vv[k-1-j]&&k-1-j+t[i]<k){vv[k-1-j+t[i]]=true;
        }
    }
}
ok2butan=false;
for(ll i=k-t[seenow];i<k;i++){
    if(vv[i])ok2butan=true;
}
if(ok2butan){
    cout << 0<< endl;
    return 0;
}

while(true){
seenow=(lower+upper)/2;

//todo:seenowに対して処理
//条件を満たすならok2butan=trueにする
vector<bool> v(k, false);
v[0]=true;
rep(i,nn){
    if(i==seenow)continue;
    rep(j,k){
        if(v[k-1-j]&&k-1-j+t[i]<k){v[k-1-j+t[i]]=true;
        }
    }
}
ok2butan=false;
for(ll i=k-t[seenow];i<k;i++){
    if(v[i])ok2butan=true;
}

if(ok2butan){
    upper=seenow;
    if(upper==lower+1){oklowest=seenow;break;}
    }
else {
    lower=seenow;
    if(upper==lower+1){oklowest=seenow+1;break;}
    }
}
cout << oklowest << endl;
return 0;
}