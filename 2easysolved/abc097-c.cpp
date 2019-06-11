#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
string s;
cin >> s;
ll k;
cin >> k;
set<string> v;

int len=(int)(s.length());
char first='z';
rep(i,len){
  if(s[i]<first)first=s[i];
}
rep(i,len){
  if(s[i]==first){
    rep1(j,k+1){
      v.insert(s.substr(i, j));
    }
  }
}
char second='z';
rep(i,len){
  if(s[i]<second&&s[i]!=first)second=s[i];
}
rep(i,len){
  if(s[i]==second){
    rep1(j,k+1){
      v.insert(s.substr(i, j));
    }
  }
}
char third='z';
rep(i,len){
  if(s[i]<third&&s[i]!=first&&s[i]!=second)third=s[i];
}
rep(i,len){
  if(s[i]==third){
    rep1(j,k+1){
      v.insert(s.substr(i, j));
    }
  }
}
auto itr=v.begin();
rep(i,k-1){
  
  itr++;
}
cout << *itr << endl;
return 0;
}