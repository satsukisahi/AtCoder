#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

//再帰を含みたいとき
template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    [[nodiscard]]
#elif defined(__GNUC__) && __GNUC_PREREQ(3, 4)
    __attribute__((warn_unused_result))
#endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    FixPoint : F {
      public :
          explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)) {}

      template <typename... Args>
      constexpr decltype(auto)
      operator()(Args &&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
}
}
;
template <typename F>
static inline constexpr decltype(auto)
makeFixPoint(F &&f) noexcept
{
  return FixPoint<F>{std::forward<F>(f)};
}

ll mo = 11;
int main()
{
  //再帰を含みたいとき
  auto fib = makeFixPoint([&](auto f, ll n) -> ll {
    return n < 2 ? n : (f(n - 1) + f(n - 2) + 1);
  });
  rep(i, 10) cout << fib(i + 1) << " ";
  cout << endl;

  //それ以外
  ll x = 10;
  auto test = [&](ll y) { return x + y; }; //&は参照 =はコピー
  cout << test(6) << endl;                 //16

  //負数対応mod処理
  auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
  
  //次に大きい整数
  auto krag = [](double krx) {double eps=1e-6;krx-=eps; if(krx>0)return (ll)krx+1LL;else return (ll)krx; };

  //mod複数掛け算
  auto modmul = [](auto... modx) {
    ll res = 1;
    for (auto modx_ : {modx...})
    {
      res *= modx_;
      res %= mo;
      res += mo;
      res %= mo;
    }
    return res;
  };

  return 0;
}
