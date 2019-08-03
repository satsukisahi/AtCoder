#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main()
{
ll n=6,ans=0;
//初期化
BinaryIndexedTree< int > bit(n);
//転倒数を求める 解10
ll tab[5]={5,4,3,2,1};
rep(i,5){
//kにxを加える
  bit.add(tab[i],1);
//閉区間[0,k]の合計を求める
  ans+=i+1-bit.sum(tab[i]);
}
return 0;
}
