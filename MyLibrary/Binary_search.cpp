#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

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
      if (abs(upper - lower) <= 1){
        if (judge(upper)) return upper;
        else return lower;
      }
    }
  };
  cout << binarysearch(0, 5) << endl; // 3

  //doubleのバージョン　x^2-2=0の解(0<x)を求める
  auto judge_d = [&](double val) { return val*val-2<0; };
  auto binarysearch_d = [&](double lowerbound, double upperbound) {
    if (!judge_d(lowerbound)) return -1.0;
    double lower = lowerbound, upper = upperbound;
    while (1){
      if (judge_d((lower + upper) / 2)) lower = (lower + upper) / 2;
      else upper = (lower + upper) / 2;
      if (fabs(upper - lower) <= 0.000001){
        return upper;
      }
    }
  };
  cout << binarysearch_d(0, 100000) << endl; // 1.41421

  //下に凸関数の三分探索　(x^2-2x-2の最小値-3(x=1)を求める)
  auto judge_f = [&](double val) { return val*val-2*val-2; };
  auto binarysearch_f = [&](double lowerbound, double upperbound) {
    if (!judge_f(lowerbound)) return -1.0;
    double lower = lowerbound, upper = upperbound;
    while (1){
      double x1=(upper-lower)  /3+lower;
      double x2=(upper-lower)*2/3+lower;
      if(judge_f(x1)>judge_f(x2))lower=x1;
      else upper=x2;
      if (fabs(upper - lower) <= 0.000001){
        return upper;
      }
    }
  };
  double ans=binarysearch_f(0, 100000);
  cout << ans << ' ' << judge_f(ans) << endl; // 1 -3

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
