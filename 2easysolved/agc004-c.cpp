#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll h , w ;
cin >> h >> w ;
string s[h];
rep(i,h){
  cin >> s[i];
}
rep(i,h){
  rep(j,w){
    if((i%2||s[i][j]=='#'||j==0)&&j!=w-1)cout << '#';
    else cout << '.';
  }
cout  << endl;
}
cout  << endl;
rep(i,h){
  rep(j,w){
    if((i%2==0||s[i][j]=='#'||j==w-1)&&j!=0)cout << '#';
    else cout << '.';
  }
cout  << endl;
}
return 0;
}