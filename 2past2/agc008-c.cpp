#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll i , o , t ;
cin >> i >> o >> t ;
ll j , l , s ;
cin >> j >> l >> s ;
ll z ;
cin >> z ;
ans+=o;
ll ii,jj,ll;
if(i%2){ans+=i/2 *2;ii=1;}
else {ans+=i;ii=0;}
if(j%2){ans+=j/2 *2;jj=1;}
else {ans+=j;jj=0;}
if(l%2){ans+=l/2 *2;ll=1;}
else {ans+=l;ll=0;}

if(ii*jj*ll){ans+=3;ii=0;jj=0;ll=0;}
if(ii*jj && l>1)ans+=1;
if(ii*ll && j>1)ans+=1;
if(jj*ll && i>1)ans+=1;

cout << ans << endl;
return 0;
}