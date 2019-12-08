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
string s ;
cin >> s ;
vector<ll> v(26);
rep(i,s.size()){
  v[s[i]-'a']++;
}
ll odd=0;ll m=-1;
rep(i,26)if(v[i]%2){odd++;m=i;}
if((s.size()%2&&odd!=1)||(s.size()%2==0&&odd!=0)){
cout << -1 << endl;
return 0;
}
rep(i,26)v[i]/=2;
vector<ll> k(s.size());
rep(i,s.size()){
  ll t=s[i]-'a';
  if(v[t]==0&&t!=m)k[i]=2;
  else if(v[t]==0&&t==m){k[i]=1;m=-1;}
  else {k[i]=0;v[t]--;}
}
ll cnt=0;
rep(i,s.size()){
  if(k[i]!=0)cnt++;
  else ans+=cnt;
}
cnt=0;
rep(i,s.size()){
  if(k[i]==2)cnt++;
  if(k[i]==1)ans+=cnt;
}
BinaryIndexedTree<ll> bit(s.size()/2 +1);
queue<ll> d[26];
cnt=0;
rep(i,s.size()){
  if(k[i]==0){d[s[i]-'a'].push(cnt);cnt++;}
}
cnt=0;
for (ll i = s.size()-1; i >= 0; i--)
{
  if(k[i]==2){
    bit.add(d[s[i]-'a'].front(), 1);
    ans += cnt + 1 - bit.sum(d[s[i]-'a'].front());
    d[s[i]-'a'].pop();
    cnt++;
  }
}
cout << ans << endl;
return 0;
}