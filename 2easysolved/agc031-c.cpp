#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , a , b ;
cin >> n >> a >> b ;
ll c=a^b;
if(__builtin_popcountll(c)%2==0){
  cout << "NO" << endl;
  return 0;
}
cout << "YES" << endl;
vector<ll> on,off;
rep(i,n){
  if((c>>i)&1LL)on.push_back(i);
  else off.push_back(i);
}
vector<ll> r;
deque<ll> l;
r.push_back(0);
r.push_back(1);
l.push_back(0);
l.push_back(1);
rep(i,off.size()-1){
  ll siz=r.size();
  rep(j,siz){
    r.push_back(r[siz-1-j]+(1LL<<(i+1)));
  }
}
ll sizz=r.size();
rep(i,sizz)r.push_back(r[sizz-1-i]);

rep(i,(on.size()-1)/2){
  ll siz=l.size();
  rep(j,siz){
    if(j==siz-1){
      l.push_back((l[j]<<2)+2);
      l.push_back((l[j]<<2)+0);
      l.push_back((l[j]<<2)+1);
      l.push_back((l[j]<<2)+3);
    }
    else if(j%2==0){
      l.push_back((l[j]<<2)+0);
      l.push_back((l[j]<<2)+1);
      l.push_back((l[j]<<2)+3);
      l.push_back((l[j]<<2)+2);
    }
    else{
      l.push_back((l[j]<<2)+2);
      l.push_back((l[j]<<2)+3);
      l.push_back((l[j]<<2)+1);
      l.push_back((l[j]<<2)+0);
    }
  }
  rep(j,siz)l.pop_front();
}
vector<ll> ans;
set<ll> s;
rep(i,(1LL<<n)){
  ll anss=0;
  rep(j,on.size()){
    anss+=((l[i/(1LL<<off.size())]>>j&1LL)<<on[j]);
  }
  rep(j,off.size()){
    anss+=((r[i%r.size()]>>j&1LL)<<off[j]);
  }
  ans.push_back(anss^a);
  s.insert(anss^a);
}
for(auto an:ans)cout << (an) << " ";
cout << endl;
//cout << s.size() << endl;

return 0;
}