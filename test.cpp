#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;


int main()
{
priority_queue<ll,vector<int>,greater<int>> q;
ll a[9]={4,5,6,8,2,3,1,9,7};
rep(i,9){
    q.push(a[i]);
}
rep(i,9){
    ll a=q.top();
    q.pop();
    cout<<a;
    

}

return 0;
}