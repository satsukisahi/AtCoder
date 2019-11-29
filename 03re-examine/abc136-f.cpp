#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
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
ll mypow(ll a,ll b){
    ll res=1;
    a%=mo;
    while(b){
        if(b&1)
            res=res*a%mo;
        a=a*a%mo;
        b>>=1;
    }
    return res;
}
int main()
{
ll n ;
cin >> n ;
ll res[n][4]={};
pair<ll,ll> p[n];
rep(i,n){
  cin >> p[i].first >> p[i].second;
}
sort(p,p+n, compare_by_b);
rep(i,n){
  p[i].second=i;
}

sort(p,p+n);
BinaryIndexedTree< int > bitlow(n);
BinaryIndexedTree< int > bithigh(n);
rep(i,n){
  res[i][0]=bitlow.sum(p[i].second);
  res[i][1]=i-res[i][0];
  bitlow.add(p[i].second,1);
  res[n-i-1][2]=bithigh.sum(p[n-i-1].second);
  res[n-i-1][3]=i-res[n-i-1][2];
  bithigh.add(p[n-i-1].second,1);
}
ll kai[n+2]={};
kai[0]=0;
kai[1]=2;
rep(i,n){
  kai[i+2]=kai[i+1]*2;
  kai[i+2]%=mo;
}
rep(i,n+1){
  kai[i+1]--;
}
ll temp;
rep(i,n){
  ans+=kai[res[i][0]]*kai[res[i][3]];ans%=mo;
  ans+=kai[res[i][1]]*kai[res[i][2]];ans%=mo;
  temp=kai[res[i][0]]*kai[res[i][1]];temp%=mo;temp*=kai[res[i][2]];ans+=temp;ans%=mo;
  temp=kai[res[i][1]]*kai[res[i][2]];temp%=mo;temp*=kai[res[i][3]];ans+=temp;ans%=mo;
  temp=kai[res[i][2]]*kai[res[i][3]];temp%=mo;temp*=kai[res[i][0]];ans+=temp;ans%=mo;
  temp=kai[res[i][3]]*kai[res[i][0]];temp%=mo;temp*=kai[res[i][1]];ans+=temp;ans%=mo;
  temp=kai[res[i][0]]*kai[res[i][1]];temp%=mo;temp*=kai[res[i][2]];temp%=mo;temp*=kai[res[i][3]];ans+=temp;ans%=mo;
}
ans+=mypow(2,n-1)*n;
ans%=mo;
cout << ans << endl;
return 0;
}
