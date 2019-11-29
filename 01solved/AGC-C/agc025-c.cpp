#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first > b.first;
    }else{
        return a.second > b.second;
    }
}

int main()
{
ll n ;
cin >> n ;
pair<ll,ll> f[n];
pair<ll,ll> b[n];
map<pair<ll,ll>,ll> s;
map<pair<ll,ll>,ll> ss;
ll ans = 0;
ll anss = 0;
rep(i,n){
  cin >> f[i].first >> f[i].second ;
  b[i]=f[i];
  s[f[i]]++;
  ss[f[i]]++;
}
sort(f,f+n,comp);
sort(b,b+n,compare_by_b);
bool te=1;
ll ff=0,bb=0;
ll now=0;
ll cnt=0;
while(cnt!=n){
  if(te){
      if(s.find(b[bb])!=s.end()&&s[b[bb]]>0){
      if(now>b[bb].second){ans+=now-b[bb].second;
      now=b[bb].second;}
      s[b[bb]]--;
      te=!te;
      cnt++;
    }
    bb++;
  }
  else{
    if(s.find(f[ff])!=s.end()&&s[f[ff]]>0){
      if(now<f[ff].first){ans+=f[ff].first-now;
      now=f[ff].first;}
      s[f[ff]]--;
      te=!te;
      cnt++;
    }
    ff++;
  }
}
ans+=abs(now);

te=0;
ff=0,bb=0;
now=0;
cnt=0;
while(cnt!=n){
  if(te){
      if(ss.find(b[bb])!=ss.end()&&ss[b[bb]]>0){
      if(now>b[bb].second){anss+=now-b[bb].second;
      now=b[bb].second;}
      ss[b[bb]]--;
      te=!te;
      cnt++;
    }
    bb++;
  }
  else{
    if(ss.find(f[ff])!=ss.end()&&ss[f[ff]]>0){
      if(now<f[ff].first){anss+=f[ff].first-now;
      now=f[ff].first;}
      ss[f[ff]]--;
      te=!te;
      cnt++;
    }
    ff++;
  }
}
anss+=abs(now);
cout << max(ans,anss) << endl;
return 0;
}
