#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
template <typename T>
struct BinaryIndexedTree
{
  vector<T> data;

  BinaryIndexedTree(ll sz)
  {
    data.assign(++sz, 0);
  }

  T sum(ll k)
  {
    T ret = 0;
    for (++k; k > 0; k -= k & -k)
      ret += data[k];
    return (ret);
  }

  void add(ll k, T x)
  {
    for (++k; k < data.size(); k += k & -k)
      data[k] += x;
  }
};
int main()
{
ll n ;
cin >> n ;
string s ;
cin >> s ;
vector<BinaryIndexedTree<ll>> v;
rep(i,26){
  BinaryIndexedTree<ll> bit(n);
  v.push_back(bit);
}
rep(i,n){
  v[s[i]-'a'].add(i,1);
}
ll q ;
cin >> q ;
rep(i,q){
  ll a , b ;
  cin >> a >> b ;
  if(a==1){
    char c;
    cin >> c;
    v[s[b-1]-'a'].add(b-1,-1);
    s[b-1]=c;
    v[c-'a'].add(b-1,1);
  }
  if(a==2){
    ll c;
    cin >> c;
    ans=0;
    rep(j,26){
      ll kk=0;
      if(b==1)kk=0;
      else kk=v[j].sum(b-2);
      if(v[j].sum(c-1)-kk>0)ans++;
    }
    cout << ans << endl;
  }
}

return 0;
}