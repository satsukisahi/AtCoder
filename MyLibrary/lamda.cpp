#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;


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
; // class FixPoint

template <typename F>
static inline constexpr decltype(auto)
makeFixPoint(F &&f) noexcept
{
    return FixPoint<F>{std::forward<F>(f)};
}


int main()
{
ll n;
cin >> n;

ll a=1;
auto fib = makeFixPoint([&](auto f, ll n) -> ll {
    return n < 2 ? n : (f(n - 1) + f(n - 2)+a);
});

rep(i, n)
    cout<< fib(i + 1) << " ";
return 0;
}
