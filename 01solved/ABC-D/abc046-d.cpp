#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
string n;
cin >> n;
int len=(int)(n.length());
ll g=0,p=0;
rep(i,len){
    if(n[i]=='g')g++;
    else p++;
}

cout << (g-p)/2 << endl;
return 0;
}
