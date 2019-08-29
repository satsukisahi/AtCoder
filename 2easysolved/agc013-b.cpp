#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


int main()
{
ll n,m;
cin >> n >> m ;
set<ll> g[n];
deque<ll> ans;
rep(i, m)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].insert(b-1);
    g[b-1].insert(a-1); //無向辺
}
bool see[n]={};
ll st=0,ed=*g[0].begin();
ans.push_back(ed+1);
ans.push_back(st+1);
see[st]=1,see[ed]=1;
bool ok=1;
while(ok){
  ok=0;
  for(auto a:g[st]){
    if(see[a]){
    }
    else{
      st=a;
      ok=1;
      see[st]=1;
      ans.push_back(st+1);
      break;
    }
  }
}
ok=1;
while(ok){
  ok=0;
  for(auto a:g[ed]){
    if(see[a]){
    }
    else{
      ed=a;
      ok=1;
      see[ed]=1;
      ans.push_front(ed+1);
      break;
    }
  }
}
cout << ans.size() << endl;

rep(i,ans.size())cout << ans[ans.size()-i-1] << " ";
return 0;
}
