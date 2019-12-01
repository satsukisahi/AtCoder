#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
string s ;
cin >> s ;
vector<ll> sum(3);
vector<vector<ll>> v(10, vector<ll>(3,0) );
rep(i,n){
  ll t=s[i]-'0';
  sum[2]+=sum[1]-v[t][2];
  v[t][2]=sum[1];
  sum[1]+=sum[0]-v[t][1];
  v[t][1]=sum[0];
  if(v[t][0]==0){
    v[t][0]=1;
    sum[0]++;
  }
}

cout << sum[2] << endl;
return 0;
}