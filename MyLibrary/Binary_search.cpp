#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll t[10] = {1, 2, 5, 6, 9, 12, 15, 19, 22, 25};
ll searchnum = 18; //18以上となるindex
//upperは常に条件を満たすlowerは常に条件を満たさない
//条件を満たす最小のindexを返す
ll lower = 0 - 1; //上限のindex
ll upper = 9;     //上限のindex
ll seenow;
bool ok;
while (true)
{
  seenow = (lower + upper) / 2;

  //todo:seenowに対して処理
  //条件を満たすならok=true;にする 満たさないならok=false;
  if (t[seenow] >= searchnum)
    ok = true;
  else
    ok = false;
  //処理ここまで
  if (ok)
  {
    upper = seenow;
    if (upper == lower + 1)
    {
      ans = seenow;
      break;
    }
  }
  else
  {
    lower = seenow;
    if (upper == lower + 1)
    {
      ans = seenow + 1;
      break;
    }
  }
}
cout << ans << endl; //7

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