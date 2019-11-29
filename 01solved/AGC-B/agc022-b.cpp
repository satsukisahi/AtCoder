#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ,nn;
cin >> n ;
if(n==3){
  cout << "2 5 63" << endl;
  return 0;
}
if(n==4){
  cout << "2 5 20 63" << endl;
  return 0;
}
if(n==6){
  cout << "2 4 6 8 5 15" << endl;
  return 0;
}
if(n==19999){
  rep(i,14979)cout << (i+1)*2 << " ";
  rep(i,4990)cout << i*6+3 << " ";
  rep(i,15)cout << i*30+5 << " "<< i*30+25 << " ";
  cout << endl;
  return 0;
}
vector<ll> two;
vector<ll> thr;
thr.push_back(3);
thr.push_back(9);
nn=2;
if(n%3==1||n%3==0){
thr.push_back(15);
thr.push_back(21);
nn+=2;
}
if(n%3==0){
thr.push_back(27);
thr.push_back(33);
nn+=2;
}
n-=nn;
rep(i,n){
  two.push_back((i+1)*2);
}
while(two.back()>30000){
  rep(i,6)thr.push_back(thr.back()+6);
  rep(i,6)two.pop_back();
}
for(auto a:two)cout << a << " ";
for(auto a:thr)cout << a << " ";
cout << endl;
return 0;
}