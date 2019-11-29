#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
string a ;
cin >> a ;
ll res[26]={};
rep(i,a.size()){
  res[a[i]-'a']++;
}
rep(i,26){
  if(res[i]>1)
  ans+=(res[i])*(res[i]-1)/2 ;
}
cout << a.size()*(a.size()-1)/2-ans+1 << endl;
return 0;
}
