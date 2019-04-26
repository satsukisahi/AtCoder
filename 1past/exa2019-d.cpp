#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

ll dp[201][100001];

int main()
{
ll ans=0,n,x;
ll mo=1000000007;
cin >> n>>x;
 
ll table[n]={};
rep(i,n) {
    cin >> table[i];
}
sort(table, table + n, greater<ll>());

//vector< vector<int> > dp(n+1, vector<int>(x+1,0) );

dp[0][x]=1;

rep(i,n){rep(j,x+1){
    if(dp[i][j]!=0){
        dp[i+1][j]+=(dp[i][j]*(n-i-1))%mo;
        dp[i+1][j]=(dp[i+1][j])%mo;
        dp[i+1][j%table[i]]+=dp[i][j];
        dp[i+1][j%table[i]]=(dp[i+1][j%table[i]])%mo;
    }
      //cout << 'a' ;
}
/* for (int d = 0; d < x; ++d) {
    cout << dp[i][d] << " ";
    }cout  << endl; */
  
}
/* for (int d = 0; d < x; ++d) {
    cout << dp[n][d] << " ";
    }cout  << endl; */

rep(i,x){
    ans=(ans+(i)*dp[n][i])%mo;
}
cout << ans << endl;
return 0;
}



