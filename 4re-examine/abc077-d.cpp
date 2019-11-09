#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = INF;
bool ch[100100]={};

int main()
{
ll n;
cin >> n;
deque<pair<int,int>> v; 
v.push_front({1,1});

ch[1]=true;
while(true){
    pair<int,int> p;
    p=v.front();
    v.pop_front();
    if(p.first==0){
        ans=p.second;
        break;
    }
    if(!ch[p.first*10%n]){
        v.push_front({(p.first*10)%n,p.second});
        ch[p.first*10%n]=true;
    }
    v.push_back({(p.first+1)%n,p.second+1});
}

cout << ans << endl;
return 0;
}