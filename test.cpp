#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main(){

vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19,7,7,7,7,7,7,4,4,8,2,2,2,2,3};

map<ll,ll> m{};
rep(i,a.size()){m[a[i]]++;}
vector<pair<int, int> > p;
for (auto i = m.begin(); i != m.end(); ++i) {
    p.push_back(make_pair(i->second,i->first ));
}
sort(p.rbegin(),p.rend());

for (int i = 0; i < p.size(); ++i) {
    cout << p[i].first<<' '<<p[i].second <<endl;
}

}