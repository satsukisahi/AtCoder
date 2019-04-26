#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

struct UnionFind {
  vector<ll> data;
  UnionFind(ll size) : data(size, -1) { }
  bool unionSet(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};


int main()
{
//整数値の入力
ll n,m;
cin >> n>>m;
ll ans[m];
//行列の入力
ll aaa,bbb;
pair<ll, ll> table[m];
for (ll i = 0; i < m; ++i) {
  
  cin >> aaa>>bbb;
  table[i] = make_pair(aaa-1, bbb-1);
}

UnionFind arr(n);

ll an=n*(n-1)/2;
ans[m-1]=an;
for (ll i = 0; i < m-1; ++i) {
  if(arr.findSet(table[m-1-i].first,table[m-1-i].second)){ans[m-2-i]=an;}
  else{
    an=an-(arr.size(table[m-1-i].first)*arr.size(table[m-1-i].second));
    ans[m-2-i]=an;
    arr.unionSet(table[m-1-i].first,table[m-1-i].second);

  }
   //cout << arr.size(table[m-1-i].first) << endl;
}


for (ll i = 0; i < m; ++i) {
  
  cout << ans[i] << endl;
}
//回答

return 0;
}

