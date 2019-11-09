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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

bool ng(int a,int b,int c){
    return (a==1&&b==2&&c==3);
}

int main()
{
ll ans=0,n;

cin >> n;

ll dp[101][4][4][4]={};
dp[0][0][0][0]=1;
for(int i = 0; i < n; i++)
for(int a = 0; a < 4; a++)
for(int b = 0; b < 4; b++)
for(int c = 0; c < 4; c++)
for(int d = 0; d < 4; d++){
    if(ng(b, c, d) || ng(c, b, d) || ng(b, d, c)) continue;
    if(ng(a, c, d) || ng(a, b, d)) continue;
    dp[i+1][b][c][d]=(dp[i+1][b][c][d]+dp[i][a][b][c])%1000000007;
}
for(int a = 0; a < 4; a++)
for(int b = 0; b < 4; b++)
for(int c = 0; c < 4; c++){
    ans=(ans+dp[n][a][b][c])%1000000007;
}
cout << ans << endl;
return 0;
}



