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
rep(i,len-1){
    if(n[i]==n[i+1]){
        cout << i+1<<" "<<i+2 << endl;
        return 0;
    }
}
rep(i,len-2){
    if(n[i]==n[i+2]){
        cout << i+1<<" "<<i+3 << endl;
        return 0;
    }
}

cout << "-1 -1" << endl;
return 0;
}
