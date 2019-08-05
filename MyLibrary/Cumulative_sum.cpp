#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
{
//一次元 t[n]に対して
ll t[6]={2,5,6,9,8,1};
ll         l=2,r=4;
ll n=6;
//構築
vector<ll> s;
s.push_back(0);
rep(i,n){
  s.push_back(t[i]+s[i]);
}
//区間和　閉区間lr t[l]～t[r] 0 ≦ l ≦ r ≦ n-1 0-indexed
ll sum=s[r+1]-s[l];
cout << sum << endl; // 23
}


{
//二次元 t[m][n]に対して
ll t[3][4]={
  {2,1,5,4},
  {1,4,6,7},
  {2,2,7,9},
};
ll m=3,n=4;  //1,5
ll x1=1,y1=0;//4,6
ll x2=2,y2=2;//2,7の部分

//構築
vector<vector<ll>> s(m+1, vector<ll>(n+1,0) );
rep(i,m)rep(j,n){
    s[i+1][j+1]=t[i][j]+s[i][j+1]+s[i+1][j]-s[i][j];
}
//範囲和 左上(x1,y1) 右下(x2,y2) 0-indexed
ll sum=s[y2+1][x2+1]-s[y2+1][x1]-s[y1][x2+1]+s[y1][x1];
cout << sum << endl;//25

}
return 0;
}
