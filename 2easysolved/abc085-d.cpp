#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;


int main()
{ 
ll n,h;
cin >> n>>h; 
ll table[n];
ll maxa=0;
rep(i,n){
    ll temp=0;
    cin >> temp>>table[i];
    if(temp>maxa)maxa=temp;
}
sort(table, table + n, greater<ll>());
rep(i,n){
    if(table[i]<maxa)break;
    else{
        ans++;
        h-=table[i];
        if(h<=0){
            cout << ans << endl;
            return 0;
        }
    }
}
ans+=(h-1)/maxa+1;

cout << ans << endl;
return 0;
} 