#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
vector< int > z_algorithm(const string &s) {
  vector< int > prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}

int main()
{
string s;
cin >> s;
string t;
cin >> t;

string ss=s;
ll num=0,num2=0;
while(ss.size()<t.size()){
  ss=ss+ss;
}
ss=ss+ss;
ss=ss+ss;
{vector< int > v=z_algorithm(t+'|'+ss);
ll te=0;
assert(v.size()==t.size()+ss.size()+1);
ll i=t.size();
bool see[v.size()]={};
while(i<t.size()+ss.size()+1){
  if(see[i]){i++;continue;}
  if(v[i]==t.size()){
    ll j=i;
    while(j<t.size()+ss.size()+1 && v[j]==t.size()){te++;see[j]=1;j+=t.size();num=max(num,te);}
    i++;
  }
  else {te=0;see[i]=1;i++;}
}
}

ss+=ss;
{vector< int > v=z_algorithm(t+'|'+ss);
ll te=0;
assert(v.size()==t.size()+ss.size()+1);
ll i=t.size();
bool see[v.size()]={};
while(i<t.size()+ss.size()+1){
  if(see[i]){i++;continue;}
  if(v[i]==t.size()){
    ll j=i;
    while(j<t.size()+ss.size()+1 && v[j]==t.size()){te++;see[j]=1;j+=t.size();num2=max(num2,te);}
    i++;
  }
  else {te=0;see[i]=1;i++;}
}
}

if(num==num2)cout << num << endl;
else cout << -1 << endl;

return 0;
}
