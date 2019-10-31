#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , k ;
cin >> n ;
bool ok=0;
rep(i,n+1){
  if(n==((i+1)*i)/2){
    k=i+1;
    ok=1;
    cout << "Yes" << endl;
    break;
  }
}
if(!ok){cout << "No" << endl;return 0;}
cout << k << endl;
vector<vector<ll>> v(k);
vector<ll> itr(k);
ll num=1;
rep(i,k){
  rep(j,i){
    v[i].push_back(v[j][itr[j]]);
    itr[j]++;
    itr[i]++;
  }
  rep(j,k-1-i){
    v[i].push_back(num);
    num++;
  }
}
rep(i,k){
  cout << k-1 << " ";
  for(auto an:v[i]){
    cout << an << " ";
  }
  cout << endl;
}

return 0;
}