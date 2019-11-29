#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll num=0;
ll n ;
cin >> n ;
ll i=0;
cout << i << endl;
string s ;
cin >> s ;
char c=s[0];
if(c=='V')return 0;
ll st=0,ed=n-1;
i=(st+ed)/2 +1;

while(num<19){
  cout << i << endl;
  cin >> s ;
  if(s[0]=='V')break;
  char cc=c;
  if((i-st)%2==0){
    if(cc=='M')cc='F';
    else cc='M';
  }
  if(s[0]==cc){
    ed=i-1;
  }
  else{
    st=i;
    c=s[0];
  }
  i=(st+ed)/2 +1;
  num++;
}

return 0;
}
