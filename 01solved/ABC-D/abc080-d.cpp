#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = 0;
ll ch[31][100100]={};
ll chh[31][100100]={};
ll chhh[100100]={};

int main()
{
ll n,c;
cin >> n>>c;

rep(i, n)
{
    ll s,t,c;
    cin >> s>>t>>c;
    if(ch[c][s]==0)ch[c][s]=1;
    else ch[c][s]=0;
    if(ch[c][t]==0)ch[c][t]=-1;
    else ch[c][t]=0;
}
rep1(i,c+1)rep1(j,100100){
    if(ch[i][j]==1){
        if(ch[i][j-1]!=-1){
            ch[i][j]=0;
            ch[i][j-1]=1;
        }
        else {
            ch[i][j]=0;
            ch[i][j-1]=0;
        }
    }
}
rep1(i,c+1)rep(j,100100){
    if(j==0) chh[i][j]=ch[i][j];
    else chh[i][j]=ch[i][j]+chh[i][j-1];
}
rep1(i,c+1)rep1(j,100100){
    chhh[j]+=chh[i][j];
}
rep1(j,100100){
    if(ans<chhh[j])ans=chhh[j];
}
/* for (int i = 0; i < 20; ++i) {
    cout << chh[1][i] << " ";
}cout  << endl;
for (int i = 0; i < 20; ++i) {
    cout << chh[2][i] << " ";
}cout  << endl;
 */
cout << ans << endl;

return 0;
}