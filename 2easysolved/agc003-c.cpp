#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
vector<ll> aa(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> comp=a;//全部突っ込む
sort(comp.begin(), comp.end());
comp.erase(unique(comp.begin(), comp.end()), comp.end());//隣接要素を削除した後の末尾イテレータからvの末尾まで削除
rep(i,a.size()){
  ll compnum=lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();//圧縮後の値
  aa[i]=compnum;
}
rep(i,n){
  if(i%2==0)continue;
  if(aa[i]%2==0)ans++;
}
cout << ans << endl;
return 0;
}