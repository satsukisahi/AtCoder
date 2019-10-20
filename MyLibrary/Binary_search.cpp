#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
  //lower側がtrue judgeがtrueとなる最もupper側のvalを返す
  //lowerboundでもfalseなら-1を返す
  vector<ll> v = {4, 7, 9, 10, 15, 18};
  ll r = 11;
  auto judge = [&](ll val) { return r > v[val]; };
  auto binarysearch = [&](ll lowerbound, ll upperbound) {
    if (!judge(lowerbound)) return -1LL;
    ll lower = lowerbound, upper = upperbound;
    while (1){
      if (judge((lower + upper) / 2)) lower = (lower + upper) / 2;
      else upper = (lower + upper) / 2;
      if (upper - lower <= 1){
        if (judge(upper)) return upper;
        else return lower;
      }
    }
  };
  cout << binarysearch(0, 5) << endl; // 3

  //STL
  //sort済みの配列、vectorで
  vector<ll> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
  ll count = 7;

  //key以上の要素の内の一番左側のイテレータを返す
  {
    auto itr = lower_bound(a.begin(), a.end(), count);
    cout << itr - a.begin() << endl; //3
  }

  //keyより大きい要素の内の一番左側のイテレータを返す
  {
    auto itr = upper_bound(a.begin(), a.end(), count);
    cout << itr - a.begin() << endl; //5
  }

  //差をとれば個数が分かる
  cout << upper_bound(a.begin(), a.end(), count) - lower_bound(a.begin(), a.end(), count) << endl; //2
  return 0;
}

/*
凸関数の3分探索
下に凸で最小値を求める場合
double lower=0,upper=1000000000;
double x1,x2;

while(true){
  x1=(upper-lower)/3+lower;
  x2=(upper-lower)*2/3+lower;
  if(x1での値>x2での値)lower=x1;
  else upper=x2;

  if(x2-x1<0.00000000001){
    ans=(x1+x2)/2;
    break;
  }
}
*/