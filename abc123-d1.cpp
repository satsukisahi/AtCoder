#include<bits/stdc++.h>
using namespace std;
using Data = pair<long long, vector<int> >;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
vector<ll> ans;
ll dp[0][0];


int main()
{
ll x,y,z,K;

cin >> x>>y>>z>>K;
ll tabx[x]={};
rep(i,x) {
    cin >> tabx[i];
}
ll taby[y]={};
rep(i,y) {
    cin >> taby[i];
}
ll tabz[z]={};
rep(i,z) {
    cin >> tabz[i];
}
sort(tabx, tabx + x, greater<ll>());
sort(taby, taby + y, greater<ll>());
sort(tabz, tabz + z, greater<ll>());

priority_queue<Data> que;
set<Data> se;
que.push(Data(tabx[0] + taby[0] + tabz[0], vector<int>({0, 0, 0})));
ll N[3]={x,y,z};
ll sum[3];

for (int k = 0; k < K; ++k) {
    auto c = que.top();que.pop();
    ans.push_back(c.first);
    sum[0]=c.first - tabx[c.second[0]] + tabx[c.second[0] + 1];
    sum[1]=c.first - taby[c.second[1]] + taby[c.second[1] + 1];
    sum[2]=c.first - tabz[c.second[2]] + tabz[c.second[2] + 1];

    // 次の三候補
    for (int iter = 0; iter < 3; ++iter) {
        if (c.second[iter] + 1 < N[iter]) {
            auto num = c.second; num[iter]++;
            auto d = Data(sum[iter], num);
            
            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }
    }
}

rep(i,K){
cout << ans[i]<< endl;
}

return 0;
}



