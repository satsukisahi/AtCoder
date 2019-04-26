#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{
ll n,k;
cin >> n>>k;
string s;
cin >> s;
vector<ll> v;

ll b=1;
if(s[0]=='0')v.push_back(0);
rep(i,n-1){
    if(s[i]==s[i+1]){
        b++;
    }
    else{
        if(s[i]=='0')b=b*-1;
        v.push_back(b);
        b=1;
    }
}
if(s[n-1]=='0')b=b*-1;
v.push_back(b);
if(s[n-1]=='0')v.push_back(0);
ll len=v.size();

/* for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
}cout  << endl; */

ll temp=0;
ll g=0,h=2*k;
rep(i,len){
    if(i>2*k)break;
    temp+=abs(v[i]);
}
ans=temp;
//cout <<ans << endl;

rep(i,(len-2*k-1)/2){
    temp=-v[g]+v[g+1]-v[h+1]+v[h+2]+temp;
    g+=2;h+=2;
    if(ans<temp)ans=temp;
    //cout <<temp << endl;
}




cout <<ans << endl;
return 0;
}



