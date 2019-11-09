#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll r , c , n ;
cin >> r >> c >> n ;
map<ll,ll> m;
rep(i,n){
  ll x , y , xx , yy ;
  cin >> x >> y >> xx >> yy ;
  if((x==0||x==r||y==0||y==c)&&(xx==0||xx==r||yy==0||yy==c)){
  if(y==0)m[x]=i;
  else if(x==r)m[r+y]=i;
  else if(y==c)m[r+c+r-x]=i;
  else if(x==0)m[2*r+c+c-y]=i;
  if(yy==0)m[xx]=i;
  else if(xx==r)m[r+yy]=i;
  else if(yy==c)m[r+c+r-xx]=i;
  else if(xx==0)m[2*r+c+c-yy]=i;
  }
}
vector<ll> v;
vector<bool> see(n);
auto itr=m.begin();
rep(i,m.size()){
  if(see[itr->second]==0){
    see[itr->second]=1;
    v.push_back(itr->second);
  }
  else{
    if(v.back()!=itr->second){
      cout << "NO" << endl;
      return 0;
    }
    v.pop_back();
  }
  itr++;
}
cout << "YES" << endl;
return 0;
}