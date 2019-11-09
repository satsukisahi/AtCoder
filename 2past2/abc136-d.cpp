#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
string s ;
cin >> s ;
ll n=s.size();
ll r[n]={};
ll temp=0;
rep(i,n){
  if(s[i]=='R')temp++;
  else {
    r[i]=temp;
    temp=0;
  }
}
ll l[n]={};
temp=0;
rep(i,n){
  if(s[n-1-i]=='L')temp++;
  else {
    l[n-1-i]=temp;
    temp=0;
  }
}
rep(i,n){
  if(r[i]!=0){
    ll te=r[i]/2;
    r[i-1]=r[i]-te;
    r[i]=te;
  }
}
rep(i,n){
  if(l[n-1-i]!=0){
    ll te=l[n-1-i]/2;
    l[n-1-i+1]=l[n-1-i]-te;
    l[n-1-i]=te;
  }
}
rep(i,n)
cout << r[i]+l[i] << " ";

cout << endl;
return 0;
}
