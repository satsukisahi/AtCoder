#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> hist(n+1);
vector<ll> ans(n+1);
vector<ll> num;
rep(i, n){
  ll aa;
  cin >> aa;
  hist[aa]++;
}
for(auto b:hist){
  if(b!=0)num.push_back(b);
}
sort(num.begin(),num.end());
vector<ll> sum;
sum.push_back(0);
rep(i,num.size()){
  sum.push_back(num[i]+sum[i]);
}
ans[num.size()]=num[0];
ll full=1;
rep(i,num.size()-1){
  while(full!=num.size()-1){
    if(num[full+1]*(full-i+1)-sum[full+2]+sum[i+1]<sum[i+1])full++;
    else break;
  }
  ans[num.size()-1-i]=num[full]+(sum[full+1]-num[full]*(full-i))/(full-i);
}
rep(i,n){
  cout << ans[i+1] << endl;
}
return 0;
}