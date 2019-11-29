#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(ll sz) {
    data.assign(++sz, 0);
  }

  T sum(ll k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(ll k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
  a[i]-=k;
}
vector<ll> s;
s.push_back(0);
rep(i,n){
  s.push_back(a[i]+s[i]);
}
vector<ll> comp=s;//全部突っ込む
sort(comp.begin(), comp.end());
comp.erase(unique(comp.begin(), comp.end()), comp.end());//隣接要素を削除した後の末尾イテレータからvの末尾まで削除
vector<ll> ss;
rep(i,s.size()){
  ll compnum=lower_bound(comp.begin(), comp.end(), s[i]) - comp.begin();//圧縮後の値
  ss.push_back(compnum);
}
BinaryIndexedTree< ll > bit(n+1);
rep(i,ss.size()){
  ans+=bit.sum(ss[i]);
  bit.add(ss[i],1);
}
cout << ans << endl;
return 0;
}
