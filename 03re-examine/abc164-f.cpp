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
vector<unsigned long long> u(n);
rep(i, n){
  cin >> u[i];
}
vector<unsigned long long> v(n);
rep(i, n){
  cin >> v[i];
}
vector<vector<vector<ll>>> a(64, vector<vector<ll>> (n, vector<ll>(n,-1) ) );
vector<vector<unsigned long long>> ans(n, vector<unsigned long long>(n,0) );

rep(k,64){
  ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
  bool a1=0,a2=0,a3=0,a4=0;
  rep(i,n){
    if(s[i]==0&&(u[i]>>k&1uLL)) {rep(j,n){a[k][i][j]=1;a1=1;}cnt1++;}
    if(t[i]==0&&(v[i]>>k&1uLL)) {rep(j,n){a[k][j][i]=1;a2=1;}cnt2++;}
    if(s[i]&&!(u[i]>>k&1uLL)) {rep(j,n){if(a[k][i][j]!=1){a[k][i][j]=0;a3=1;}else{cout << -1 << endl;return 0;}}cnt3++;}
    if(t[i]&&!(v[i]>>k&1uLL)) {rep(j,n){if(a[k][j][i]!=1){a[k][j][i]=0;a4=1;}else{cout << -1 << endl;return 0;}}cnt4++;}
  }

  if(a1&&a2)rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=0;
  if(a3&&a4)rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=1;

  if(a1&&a3){
    rep(i,n)if(a[k][i][0]==-1)a[k][i][0]=1;
  }
  if(a2&&a4){
    rep(i,n)if(a[k][0][i]==-1)a[k][0][i]=1;
  }

  if(a1&&a2==0&&a3==0&&a4==0&&cnt1==n)rep(i,n)if(t[i]==0&&!(v[i]>>k&1uLL)){cout << -1 << endl;return 0;}
  if(a1==0&&a2&&a3==0&&a4==0&&cnt2==n)rep(i,n)if(s[i]==0&&!(u[i]>>k&1uLL)){cout << -1 << endl;return 0;}
  if(a1==0&&a2==0&&a3&&a4==0&&cnt3==n)rep(i,n)if(t[i]&&(v[i]>>k&1uLL)){cout << -1 << endl;return 0;}
  if(a1==0&&a2==0&&a3==0&&a4&&cnt4==n)rep(i,n)if(s[i]&&(u[i]>>k&1uLL)){cout << -1 << endl;return 0;}

  if(a1&&a2==0&&a3==0&&a4==0&&cnt1!=n)rep(i,n)if(s[i]&&(u[i]>>k&1uLL))rep(j,n){
    if(t[j]&&(v[j]>>k&1uLL)){a[k][i][j]=1;break;}
    else{
      ll ok=0;
      rep(l,n)if(a[k][l][j]==-1)ok++;
      if(ok>=2){a[k][i][j]=1;break;}
    }
  }
  if(a1==0&&a2&&a3==0&&a4==0&&cnt2!=n)rep(i,n)if(t[i]&&(v[i]>>k&1uLL))rep(j,n){
    if(s[j]&&(u[j]>>k&1uLL)){a[k][j][i]=1;break;}
    else{
      ll ok=0;
      rep(l,n)if(a[k][j][l]==-1)ok++;
      if(ok>=2){a[k][j][i]=1;break;}
    }
  }
  if(a1==0&&a2==0&&a3&&a4==0&&cnt3!=n)rep(i,n)if(s[i]==0&&!(u[i]>>k&1uLL))rep(j,n){
    if(t[j]==0&&!(v[j]>>k&1uLL)){a[k][i][j]=0;break;}
    else{
      ll ok=0;
      rep(l,n)if(a[k][l][j]==-1)ok++;
      if(ok>=2){a[k][i][j]=0;break;}
    }
  }
  if(a1==0&&a2==0&&a3==0&&a4&&cnt4!=n)rep(i,n)if(t[i]==0&&!(v[i]>>k&1uLL))rep(j,n){
    if(s[j]==0&&!(u[j]>>k&1uLL)){a[k][j][i]=0;break;}
    else{
      ll ok=0;
      rep(l,n)if(a[k][j][l]==-1)ok++;
      if(ok>=2){a[k][j][i]=0;break;}
    }
  }
  if(a1==0&&a2==0&&a3&&a4==0&&cnt3!=n)rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=1;
  if(a1==0&&a2==0&&a3==0&&a4&&cnt4!=n)rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=1;
  if(a1==0&&a2==0&&a3==0&&a4==0){rep(i,n)a[k][i][i]=1;}
  rep(i,n)rep(j,n)if(a[k][i][j]==-1)a[k][i][j]=0;
}

rep(k,64)rep(i,n){
  if(s[i]==0&&(u[i]>>k&1uLL))rep(j,n)if(a[k][i][j]==0){cout << -1 << endl;return 0;}
  if(s[i]==0&&!(u[i]>>k&1uLL)){
    bool ok=0;
    rep(j,n)if(a[k][i][j]==0)ok=1;
    if(!ok){cout << -1 << endl;return 0;}
  }
  if(s[i]==1&&!(u[i]>>k&1uLL))rep(j,n)if(a[k][i][j]==1){cout << -1 << endl;return 0;}
  if(s[i]==1&&(u[i]>>k&1uLL)){
    bool ok=0;
    rep(j,n)if(a[k][i][j]==1)ok=1;
    if(!ok){cout << -1 << endl;return 0;}
  }
  if(t[i]==0&&(v[i]>>k&1uLL))rep(j,n)if(a[k][j][i]==0){cout << -1 << endl;return 0;}
  if(t[i]==0&&!(v[i]>>k&1uLL)){
    bool ok=0;
    rep(j,n)if(a[k][j][i]==0)ok=1;
    if(!ok){cout << -1 << endl;return 0;}
  }
  if(t[i]==1&&!(v[i]>>k&1uLL))rep(j,n)if(a[k][j][i]==1){cout << -1 << endl;return 0;}
  if(t[i]==1&&(v[i]>>k&1uLL)){
    bool ok=0;
    rep(j,n)if(a[k][j][i]==1)ok=1;
    if(!ok){cout << -1 << endl;return 0;}
  }
}
rep(k,64)rep(i,n)rep(j,n)ans[i][j]+=(a[k][i][j]<<k);
/* rep(i,n){
  unsigned long long te=0,ye=0;
  if(s[i]==1)rep(j,n)te|=ans[i][j];
  else {te=ans[i][0];rep(j,n)te&=ans[i][j];}
  if(t[i]==1)rep(j,n)ye|=ans[j][i];
  else {ye=ans[0][i];rep(j,n)ye&=ans[j][i];}
  if(te!=u[i])assert(0);
  if(ye!=v[i])assert(0);
} */
rep(i,n){
  rep(j,n)cout << ans[i][j] << " ";
  cout << endl;
}

return 0;
}