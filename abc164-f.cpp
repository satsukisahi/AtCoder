#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> s(n);
rep(i, n){
  cin >> s[i];
}
vector<ll> t(n);
rep(i, n){
  cin >> t[i];
}
vector<ll> u(n);
rep(i, n){
  cin >> u[i];
}
vector<ll> v(n);
rep(i, n){
  cin >> v[i];
}
vector<vector<vector<ll>>> a(63, vector<vector<ll>> (n, vector<ll>(n,-1) ) );
vector<vector<ll>> ans(n, vector<ll>(n,0) );

rep(k,63){
  ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
  bool a1=0,a2=0,a3=0,a4=0;
  rep(i,n){
    if(s[i]==0&&(u[i]>>k&1LL)) {rep(j,n){a[k][i][j]=1;a1=1;}cnt1++;}
    if(t[i]==0&&(v[i]>>k&1LL)) {rep(j,n){a[k][j][i]=1;a2=1;}cnt2++;}
    if(s[i]&&!(u[i]>>k&1LL)) {rep(j,n){if(a[k][i][j]!=1){a[k][i][j]=0;a3=1;}else{cout << -1 << endl;return 0;}}cnt3++;}
    if(t[i]&&!(v[i]>>k&1LL)) {rep(j,n){if(a[k][j][i]!=1){a[k][j][i]=0;a4=1;}else{cout << -1 << endl;return 0;}}cnt4++;}
  }

  if(a1&&a2)rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=0;
  if(a3&&a4)rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=1;
  if(a1&&a3){
    rep(i,n)if(a[k][i][0]==-1)a[k][i][0]=1;
  }
  if(a2&&a4){
    rep(i,n)if(a[k][0][i]==-1)a[k][0][i]=1;
  }
  if(a1&&a2==0&&a3==0&&a4==0&&cnt1==n)rep(i,n)if(t[i]==0&&!(v[i]>>k&1LL)){cout << -1 << endl;return 0;}
  if(a1&&a2==0&&a3==0&&a4==0&&cnt1!=n)rep(i,n)if(a[k][i][0]==-1)a[k][i][i]=1;
  if(a1==0&&a2&&a3==0&&a4==0&&cnt2==n)rep(i,n)if(s[i]==0&&!(u[i]>>k&1LL)){cout << -1 << endl;return 0;}
  if(a1==0&&a2&&a3==0&&a4==0&&cnt2!=n)rep(i,n)if(a[k][0][i]==-1)a[k][i][i]=1;

  if(a1==0&&a2==0&&a3&&a4==0&&cnt3==n)rep(i,n)if(t[i]&&(v[i]>>k&1LL)){cout << -1 << endl;return 0;}
  if(a1==0&&a2==0&&a3&&a4==0&&cnt3!=n)rep(i,n)if(a[k][i][0]==-1)a[k][i][i]=0;
  if(a1==0&&a2==0&&a3==0&&a4&&cnt4==n)rep(i,n)if(s[i]&&(u[i]>>k&1LL)){cout << -1 << endl;return 0;}
  if(a1==0&&a2==0&&a3==0&&a4&&cnt4!=n)rep(i,n)if(a[k][0][i]==-1)a[k][i][i]=0;

  if(a1==0&&a2==0&&a3==0&&a4==0){rep(i,n)a[k][i][i]=1;}
  rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=0;
}

rep(k,63)rep(i,n){
  if(s[i]==0&&(u[i]>>k&1LL))rep(j,n)if(a[k][i][j]==0){cout << -1 << endl;return 0;}
  if(s[i]==0&&!(u[i]>>k&1LL)){
    bool ok=0;
    rep(j,n)if(a[k][i][j]==0)ok=1;
    if(!ok){cout << -1 << endl;return 0;}
  }
  if(t[i]==1&&!(v[i]>>k&1LL))rep(j,n)if(a[k][j][i]==1){cout << -1 << endl;return 0;}
  if(t[i]==1&&(v[i]>>k&1LL)){
    bool ok=0;
    rep(j,n)if(a[k][j][i]==1)ok=1;
    if(!ok){cout << -1 << endl;return 0;}
  }
}

rep(k,63)rep(i,n)rep(j,n)ans[i][j]+=(a[k][i][j]<<k);
rep(i,n){
  rep(j,n)cout << ans[i][j] << " ";
  cout << endl;
}
return 0;
}