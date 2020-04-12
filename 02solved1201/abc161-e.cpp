#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , k , c ;
cin >> n >> k >> c ;
string s ;
cin >> s ;
vector<ll> v(n,0);
vector<ll> vv(n,0);
ll l=-100000000;
ll cnt=1;
rep(i,n){
  if(i-l<=c)continue;
  if(s[i]=='o'){
    l=i;
    v[i]=cnt;
    cnt++;
  }
}
l=-100000000;
cnt=k;
rep(i,n){
  if(i-l<=c)continue;
  if(s[n-1-i]=='o'){
    l=i;
    vv[n-1-i]=cnt;
    cnt--;
  }
}
rep(i,n){
  if(v[i]!=0&&v[i]==vv[i])cout << i+1 << endl;
}
return 0;
}