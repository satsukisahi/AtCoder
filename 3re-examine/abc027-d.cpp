#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
string n;
cin >> n;
int len=(int)(n.length());
vector<ll> v;
ll res=0;
rep(i,len){
    if(n[len-i-1]=='+')res++;
    if(n[len-i-1]=='-')res--;
    if(n[len-i-1]=='M')v.push_back(res);
}
sort(v.begin(),v.end());
rep(i,v.size()){
    if(i<v.size()/2){
        ans-=v[i];
    }
    else ans+=v[i];
}

cout << ans << endl;
return 0;
}
