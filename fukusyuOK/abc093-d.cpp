#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{ 
ll a,b;
cin >> a>>b; 
if(a==1&&b==1){
    cout << "1 2" << endl;
    cout << "#." << endl;
return 0;
}
char tab[100][100];

for (int i = 0; i < 100; ++i){
for (int j = 0; j < 100; ++j) {
    tab[i][j]='.';
}}
ll ma=max(a,b);
ll mi=ma-1-min(a,b);
rep(i,ma-1){
    tab[(i/24)*4][4*(i%24)]='#';
    tab[(i/24)*4][4*(i%24)+1]='#';
    tab[(i/24)*4][4*(i%24)+2]='#';
    tab[(i/24)*4+1][4*(i%24)]='#';
    tab[(i/24)*4+1][4*(i%24)+2]='#';
    tab[(i/24)*4+2][4*(i%24)]='#';
    tab[(i/24)*4+2][4*(i%24)+1]='#';
    tab[(i/24)*4+2][4*(i%24)+2]='#';
    if(mi>0){
        if(i%24!=23)tab[(i/24)*4][4*(i%24)+3]='#';
        else tab[(i/24)*4+3][0]='#';
        
        mi--;
    }
}
if(a<b){
for (int i = 0; i < 100; ++i){
for (int j = 0; j < 100; ++j) {
    if(tab[i][j]=='.') tab[i][j]='#';
    else tab[i][j]='.';
}}
}
cout << "100 100" << endl;
if(a==b)tab[99][99]='#';
for (int i = 0; i < 100; ++i){
for (int j = 0; j < 100; ++j) {
    cout << tab[i][j] ;
}cout  << endl;}
return 0;
}
