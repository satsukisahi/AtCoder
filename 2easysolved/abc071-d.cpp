#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 3;

int main()
{
ll n;
cin >> n;
string s1,s2;
cin >> s1;
cin >> s2;
ll see=0,past=0;
if(s1[see]==s2[see]){see=1;past=1;}
else{see=2;past=0;ans=6;}
while(see<n){
    if(s1[see]==s2[see]){
        see+=1;
        ans=ans*(past+1);
        ans%=mo;
        past=1;
    }
    else{
        see+=2;
        ans=ans*(past*(-1)+3);
        ans%=mo;
        past=0;
    }
}

cout << ans << endl;
return 0;
}