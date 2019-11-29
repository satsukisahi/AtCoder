#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 9223372036854775807;
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll d[n][n] = {};
rep(i, n)rep(j,n)
{
    cin >> d[i][j];
    ans+=d[i][j];
}
bool a[n][n]={};

//cout << ans<< endl;
ll temp=0;
for (int k = 0; k < n; k++)
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++){
            //d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            if(d[i][j]> d[i][k] + d[k][j]){
                cout << -1 << endl;
                return 0;
            }
            if(d[i][j]== d[i][k] + d[k][j]&&k!=j&&k!=i){
                a[i][j]=1;
               // cout <<k+1<<' '<<i+1<<' '<<j+1<<' '<< d[i][j]<< endl;
            }
        }



rep(i,n)rep(j,i){
    if(a[j][i]==0)temp+=d[i][j];
}
cout << temp<< endl;
return 0;
}