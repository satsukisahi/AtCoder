#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
cout << '?' ;
rep(i,n)cout << ' ' << i+1 ;
cout << endl;

auto input = []() { string st;cin >> st; if(st=="-1")assert(0); return st=="Blue"; };
bool f=input();


auto judge = [&](ll val) { 
  cout << '?' ;
  rep(i,n)cout << ' ' << i+val ;
  cout << endl;
  return f==input();
};
auto binarysearch = [&](ll lowerbound, ll upperbound) {
  ll lower = lowerbound, upper = upperbound;
  while (1){
    if (judge((lower + upper) / 2)) lower = (lower + upper) / 2;
    else upper = (lower + upper) / 2;
    if (abs(upper - lower) <= 1){
      if (judge(upper)) return upper;
      else return lower;
    }
  }
};
auto k=binarysearch(1,n+1);
vector<char> v(2*n+1,'a');
v[k]=(f ? 'B' : 'R');
v[k+n]=(!f ? 'B' : 'R');
for(ll i=1;i<k;i++){
  cout << '?' ;
  rep(j,n-1)cout << ' ' << j+k+1 ;
  cout << ' ' << i;
  cout << endl;
  v[i]=(input() ? 'B' : 'R');
}
for(ll i=k+n+1;i<=2*n;i++){
  cout << '?' ;
  rep(j,n-1)cout << ' ' << j+k+1 ;
  cout << ' ' << i;
  cout << endl;
  v[i]=(input() ? 'B' : 'R');
}
for(ll i=k+1;i<k+n;i++){
  cout << '?' ;
  rep(j,n-1)if(j+k+1!=i)cout << ' ' << j+k+1 ;
  cout << ' ' << k;
  cout << ' ' << k+n;
  cout << endl;
  v[i]=(!input() ? 'B' : 'R');
}
cout << "! " ;
rep(i,2*n)cout << v[i+1];
cout << endl;

return 0;
}