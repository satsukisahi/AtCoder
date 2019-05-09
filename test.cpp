#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

inline int Dice()
{
    return rand() % 100 + 1;
}

int main()
{
    int i;

    for(i = 0; i < 200; i++)
        cout <<  Dice() << ' ';
    cout << flush;

    return 0;
}