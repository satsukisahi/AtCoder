#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
string s="hello";

//長さ
cout << s.size() << endl;//5
//i文字目
cout << s[1] << endl;//e
//部分文字列 開始位置,取り出す長さ
s.substr(1,2);//el
//要素削除 1番目から2個の要素を削除
s.erase(1,2);//hlo

//数字を文字列に
string num=to_string(31415);
//stringを数字に
ll num2=stoll(num);

//右詰め左詰めゼロ埋め
std::cout << std::right << std::setw(4) <<  12 << endl; // "  12"
std::cout << std::left << std::setw(4) <<  12 << endl; // "12  "
std::cout << std::setfill('0') << std::right << std::setw(4) << 12 << endl; // "0012"
std::cout << std::setfill('0') << std::left  << std::setw(4) << 12 << endl; // "1200"

return 0;
}
