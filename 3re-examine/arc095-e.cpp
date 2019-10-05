#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
string s[12];
bool ng=1;
void solve(ll h,ll w,vector<ll> v,vector<bool> use,ll num,ll mm){
  if(num==h){
    string ss[12];
    rep(i,w)rep(j,h)ss[i]+=s[v[j]][i];
    string sss[12];
    rep(i,w)rep(j,h)sss[i]+=s[v[h-1-j]][i];
    vector<bool> ch(w);
    rep(i,w)rep(j,w){
      if(i==j)continue;
      if(ch[i]==0&&ch[j]==0&&ss[i]==sss[j]){
        ch[i]=1;ch[j]=1;
      }
    }
    ll nu=0;
    rep(i,w)if(!ch[i])nu++;
    if(( w%2==1 && nu==1 )||( w%2==0 && nu==0) ){
      if(ng)cout << "YES" << endl;
      ng=0;
    }
  }
  else if(num==h-1){
    rep(i,h)if(use[i]==0)v[h/2]=i;
    solve(h,w,v,use,num+1,mm);
  }
  else{
    rep(i,h)if(use[i]==0 && i!=mm){v[num/2]=i;use[i]=1;break;}
    rep(i,h){
      vector<ll> vv=v;
      vector<bool> usee=use;
      if(use[i]==0){
        vv[h-1-num/2]=i;usee[i]=1;
        string a1=s[v[num/2]],a2=s[vv[h-1-num/2]];
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        if(a1==a2)solve(h,w,vv,usee,num+2,mm);
      }
    }
  }
}

int main()
{
ll h , w ;
cin >> h >> w ;
rep(i,h){
  cin >> s[i];
}
vector<ll> v(h);
vector<bool> use(h);
if(h%2)rep(i,h)solve(h,w,v,use,0,i);
else solve(h,w,v,use,0,-1);
if(ng)cout << "NO" << endl;
}