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
if(n[0]==n[len-1]){
    if(len%2)cout << "Second" << endl;
    else cout << "First" << endl;
}
else {
    if(len%2)cout << "First" << endl;
    else cout << "Second" << endl;
}


return 0;
}
