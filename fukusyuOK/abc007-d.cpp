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

int main()
{
ll ans=0,n;
ll c;
string a,b;
ll ac,bc;

cin >> c>>b;
a=to_string(c-1);
ll dp[20][2][2]={};
dp[0][0][0]=1;
int len=(int)(a.length());
int D;
rep(i,len){
    D=int(a[i]-'0');
    rep(j,2)rep(k,2)for(int d = 0; d <= ( j ? 9 : D ); ++d ){
    dp[i+1][j||(d<D)][k||d==4||d==9]+=dp[i][j][k];
}
}
ac=dp[len][0][1] + dp[len][1][1];

ll dpp[20][2][2]={};
dpp[0][0][0]=1;
len=(int)(b.length());
rep(i,len){
    D=int(b[i]-'0');
    rep(j,2)rep(k,2)for(int d = 0; d <= ( j ? 9 : D ); ++d ){
    dpp[i+1][j||(d<D)][k||d==4||d==9]+=dpp[i][j][k];
}
}
bc=dpp[len][0][1] + dpp[len][1][1];

cout << bc-ac << endl;
return 0;
}



