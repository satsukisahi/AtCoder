#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 10000;

int main()
{
vector<string> v(3);
cin >> v[0] >> v[1] >> v[2] ;
sort(v.begin(),v.end());
do{
vector<bool> a(v[0].size()+1000);
vector<bool> b(v[0].size()+1000);
vector<bool> c(v[1].size()+1000);
rep(i,v[0].size())rep(j,v[1].size())if(i+j<v[0].size()&&v[0][i+j]!='?'&&v[1][j]!='?'&&v[0][i+j]!=v[1][j]){a[i]=1;break;}
rep(i,v[0].size())rep(j,v[2].size())if(i+j<v[0].size()&&v[0][i+j]!='?'&&v[2][j]!='?'&&v[0][i+j]!=v[2][j]){b[i]=1;break;}
rep(i,v[1].size())rep(j,v[2].size())if(i+j<v[1].size()&&v[1][i+j]!='?'&&v[2][j]!='?'&&v[1][i+j]!=v[2][j]){c[i]=1;break;}
rep(i,v[0].size()+1000)rep(j,v[1].size()+1000){
  if(!a[i]&&((i+j>v[0].size())||(!b[i+j]))&&!c[j])ans=min(ans,max({(ll)v[0].size(),(ll)v[1].size()+i,(ll)v[2].size()+i+j}));
}
}while(next_permutation(v.begin(),v.end()));
cout << ans << endl;
return 0;
}
