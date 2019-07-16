#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,a;
cin >> n>>a;

string s;
cin >> s;
ll b[n+1] = {};
rep(i, n){
    cin >> b[i+1];
}
bool see[n+1]={};
ll now=a;
ll cnt=0;
vector<ll> vv;
while(1){
    now=b[now];
    vv.push_back(now);
    cnt++;
    if(see[now]){vv.pop_back(); break;}
    see[now]=1;
}
vector<ll> v;
while(1){
    v.push_back(now);
    now=b[now];
    if(!see[now]){v.pop_back(); break;}
    see[now]=0;
}
cnt-=+1;


int len=(int)(s.length());
ll temp=0;

cnt-=v.size();
rep(i,len){
    temp*=10;
    temp+=(s[i]-'0');
    if(temp>n)temp=(temp-cnt-1)%v.size()+cnt+1;
}
ll k=temp;
ll tes=0;


if(k<=cnt)ans=vv[k-1];
else{
    k=(k-cnt-1)%v.size();
    ans=vv[cnt+k];
}


cout << ans << endl;
return 0;
}
