#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
multiset<ll> s;
rep(i, 1LL<<n){
  ll a;
  cin >> a;
  s.insert(a);
}
vector<ll> v;
auto itr=s.end();
itr--;
v.push_back(*itr);
s.erase(itr);

ll num=1;
rep(i,n){
  sort(v.rbegin(),v.rend());
  ll siz=v.size();
  itr=s.end();
  itr--;
  rep(j,siz){
    if(v[j]<=*itr){
      if(itr==s.begin()){
        cout << "No" << endl;
        return 0;
      }
      j--;
      itr--;
    }
    else{
      v.push_back(*itr);
      if(s.size()!=1){
        if(itr==s.begin()&&j!=siz-1){
          cout << "No" << endl;
          return 0;
        }
        itr=s.erase(itr);
        itr--;
        }

    }
  }
  num=v.size();
}

cout << "Yes" << endl;
return 0;
}
