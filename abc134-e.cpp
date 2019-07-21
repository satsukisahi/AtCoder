#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807


int main()
{
ll n;
cin >> n;
ll t[n] = {};
rep(i, n){
    cin >> t[i];
}

deque<ll> v; 
v.push_front(t[0]);
rep(i,n-1){
    if(lower_bound(v.begin(),v.end(), t[i+1])==v.begin()){
        v.push_front(t[i+1]);
    }
    else {
        auto itr=lower_bound(v.begin(),v.end(), t[i+1]);
        itr--;
        *itr=t[i+1];
    }
}
cout << v.size() << endl;
return 0;
}
