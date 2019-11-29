#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , l , x ;
cin >> n >> l >> x ;
set<ll> stb;
multiset<ll> st;
multiset<ll> dist;
stb.insert(x);
st.insert(min(x,l-x));
st.insert(1e+10);
st.insert(1e+10 +1);
st.insert(-1e+10);
st.insert(-1e+10 -1);
dist.insert(1e+10-(-1e+10));
dist.insert(1e+10 +1 - min(x,l-x));
dist.insert(min(x,l-x) - (-1e+10 -1));
vector<ll> ans;
vector<ll> a(n);
rep(i,n){
  cin >> a[i];
}

rep(i,n){
  if(stb.find(a[i])==stb.end()){
    stb.insert(a[i]);
    auto itr=st.insert(min(a[i],l-a[i]));
    auto itr1=itr;itr1--;
    auto itr0=itr1;itr0--;
    auto itr2=itr;itr2++;
    auto itr3=itr2;itr3++;
    dist.erase(dist.find(*itr2-*itr0));
    dist.erase(dist.find(*itr3-*itr1));
    dist.insert(*itr-*itr0);
    dist.insert(*itr3-*itr);
    dist.insert(*itr2-*itr1);
    if(stb.size()==2){
      auto itr00=stb.begin();
      auto itr11=itr00;itr11++;
      ans.push_back(max(*itr11-*itr00,abs((l-*itr11)-*itr00)));
      continue;
    }
    auto itrex1=st.end();rep(i,3)itrex1--;
    auto itrex0=itrex1;itrex0--;
    ans.push_back(min(*dist.begin(),l-*itrex0-*itrex1));
  }
  else{
    stb.erase(a[i]);
    auto itr=st.find(min(a[i],l-a[i]));
    auto itr1=itr;itr1--;
    auto itr0=itr1;itr0--;
    auto itr2=itr;itr2++;
    auto itr3=itr2;itr3++;
    dist.erase(dist.find(*itr-*itr0));
    dist.erase(dist.find(*itr3-*itr));
    dist.erase(dist.find(*itr2-*itr1));
    dist.insert(*itr2-*itr0);
    dist.insert(*itr3-*itr1);
    st.erase(itr);
    if(stb.size()==2){
      auto itr00=stb.begin();
      auto itr11=itr00;itr11++;
      ans.push_back(max(*itr11-*itr00,abs((l-*itr11)-*itr00)));
      continue;
    }
    auto itrex1=st.end();rep(i,3)itrex1--;
    auto itrex0=itrex1;itrex0--;
    ans.push_back(min(*dist.begin(),l-*itrex0-*itrex1));
  }
}

//cout << endl;
for(auto a:ans)cout << a << endl;

return 0;
}