#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

void solve(vector<vector<ll>> &v,ll l,ll r,ll num){
  if(r-l==1)v[l][r]=num;
  else{
    ll av=(l+r)/2;
    for (ll i = l; i <= av; i++)
    {
      for (ll j = av+1; j <= r; j++)
      {
        v[i][j]=num;
      }
    }
    solve(v,l,av,num+1);
    if(av+1!=r)solve(v,av+1,r,num+1);
  }
}


int main()
{
ll n ;
cin >> n ;
vector<vector<ll>> v(n+1, vector<ll>(n+1,0) );
solve(v,1,n,1);
rep(i,n-1){
  rep(j,n-i-1){
    cout << v[i+1][j+i+2] << " ";
}
cout << endl;
}
return 0;
}
