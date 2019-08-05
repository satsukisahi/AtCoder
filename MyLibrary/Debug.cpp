#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n=5;
vector<ll> v(5);
v={2,5,4,8,9};

//配列の中身を見る
for (int i = 0; i < n; ++i) {
    cout << v[i] << " ";
}cout  << endl;

//vectorの中身を見る
for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";    
}cout  << endl;

for (auto& u : v) {
    cout << u << " ";
}cout  << endl;

ll m=3;
ll t[m][n]={
  {2,1,5,4,5},
  {1,4,6,7,1},
  {2,2,7,9,6},
};
//2次元配列の中身を見る
for (int i = 0; i < m; ++i){
for (int j = 0; j < n; ++j) {
    cout << t[i][j] << " ";
}cout  << endl;}

return 0;
}
