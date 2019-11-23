#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll h , w , k ;
cin >> h >> w >> k ;
string s[h];
rep(i,h){
  cin >> s[i];
}
ll c=0;
vector<vector<ll>> v(h, vector<ll>(w,0) );
rep(i,h){
  bool a=0;
  rep(j,w){
    if(s[i][j]=='#'){a=1;c++;v[i][j]=c;}
    else if(a)v[i][j]=c;
  }
}
rep(i,h){
  rep(j,w-1){
    if(v[i][w-j-2]==0)v[i][w-j-2]=v[i][w-j-1];
  }
}
rep(i,w){
  rep(j,h-1){
    if(v[j+1][i]==0)v[j+1][i]=v[j][i];
  }
}
rep(i,w){
  rep(j,h-1){
    if(v[h-j-2][i]==0)v[h-j-2][i]=v[h-j-1][i];
  }
}

rep(i,h){
  rep(j,w){
    cout << v[i][j] << ' ';
    
  }
  cout << endl;
}
return 0;
}