#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
//回答が整数の場合
int ans;
//整数値の入力
int n,m;
cin >> n >> m;
//行列の入力
tuple<int, int, int> data[m];
//年、県、順番

for (int i = 0; i < m; ++i) {
     int p, y;
        cin >> p >> y;
        data[i] = make_tuple(y, p, i);
}

sort(data,data+m);


int cnt[n + 1];
fill(cnt, cnt + n + 1, 0);
// 各県に今属している市の数

pair<int, int> id[m];
// 各市の(属する県、県の中で誕生した順番)

for (int i = 0; i < m; ++i) {
    int y, p, idx;
    tie(y, p, idx) = data[i];
    ++cnt[p];
    id[idx] = make_pair(p, cnt[p]);
}

for (int i = 0; i < m; ++i) {
    // setwで文字数、setfillで埋める文字を指定
    // iomanipをincludeする必要があるので注意
    cout << setw(6) << setfill('0') << id[i].first;
    cout << setw(6) << setfill('0') << id[i].second << endl;
}
return 0;
}