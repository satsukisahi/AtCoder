#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
string s ;
cin >> s ;
vector<vector<ll>> g(n);
vector<vector<ll>> num(n,vector<ll>(2));
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
  if(s[b-1]=='A')num[a-1][0]++;
  if(s[b-1]=='B')num[a-1][1]++;
  if(s[a-1]=='A')num[b-1][0]++;
  if(s[a-1]=='B')num[b-1][1]++;
}
vector<bool> liv(n,1);
queue<ll> q;
rep(i,n)if(num[i][0]==0||num[i][1]==0){q.push(i);liv[i]=0;}
while(!q.empty()){
  ll p=q.front();
  q.pop();
  ll a=((s[p]=='A') ? 0 : 1 );
  for(auto r:g[p]){
    if(liv[r]==0)continue;
    num[r][a]--;
    if(num[r][a]==0){q.push(r);liv[r]=0;}
  }
}
bool ok=0;
rep(i,n)if(num[i][0]>0&&num[i][1]>0)ok=1;
cout << (ok ? "Yes" : "No" ) << endl;
return 0;
}