#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];
int select(vector<ll> &a, ll k) {
  for (int l = 0, r = a.size()-1; l <= r; ) {
    int p = a[(l+r)/2];
    int i = l-1, j = r+1;
    while (1) {
      while (a[++i] < p);
      while (a[--j] > p);
      if (i >= j) break;
      swap(a[i], a[j]);
    }
    if (k == i-l) return a[i];
    else if (k < i-l) { r = i-1; }
    else if (k > i-l) { k -= (i-l+1); l = j+1; }
  }
  return -99999999; // k < 0 || k >= n
}
int main(){
rep(i,15){
    vector<ll> hoge={5,9,1,6,4,2,8,3,7};
    cout << i-3<<' '<<select(hoge,i-3) << endl;
    }
    vector<ll> hoge={5,9,1,6,4,2,8,3,7};
cout <<select(hoge,8) << endl;
}