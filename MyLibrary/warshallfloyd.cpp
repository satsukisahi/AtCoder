#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

void warshallfloyd(vector<vector<ll>> &d)
{
  for (int k = 0; k < d.size(); k++)
    for (int i = 0; i < d.size(); i++)
      for (int j = 0; j < d.size(); j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
  ll n;                                        //頂点数
  ll m;                                        //辺数
  vector<vector<ll>> d(n, vector<ll>(n, INF)); //d[u][v]はuからvへコスト　存在しないとINF、d[i][i]=0
  rep(i, n) { d[i][i] = 0; }
  rep(i, m)
  {
    //input
  }
  warshallfloyd(d);
  //rep(i, n) if (d[i][i] < 0){負閉路が存在}

  return 0;
}
