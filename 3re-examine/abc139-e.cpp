#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
deque<ll> v[n];
rep(i,n)rep(j,n-1){
  ll a;
  cin >> a;
  v[i].push_back(a-1);
}
ll num=0;
bool see[n]={};
vector<ll> s;
vector<ll> ss;
rep(i,n){
  s.push_back(i);
}
while(num<n*(n-1)/2){
  ans++;
  bool ng=1;
  rep(k,s.size()){
    ll i=s[k];
    if(v[i].size()>0&&see[i]==0){
      if(v[v[i][0]][0]==i&&see[v[i][0]]==0){
        ng=0;
        num++;
        see[i]=1;
        see[v[i][0]]=1;
        ss.push_back(i);
        ss.push_back(v[i][0]);
        v[v[i][0]].pop_front();
        v[i].pop_front();
      }
    }
  }
  sort(ss.begin(),ss.end());
  s=ss;
  ss.clear();
  rep(i,n)see[i]=0;
  if(ng){
    cout << -1 << endl;
    return 0;
  }
}
cout << ans << endl;
return 0;
}
