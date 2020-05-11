#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
class FastFourierTransform
{
private:
  static void dft(vector<complex<double>> &func, int inverse)
  {
    int sz = func.size();
    if (sz == 1)
      return;
    vector<complex<double>> veca, vecb;
    rep(i, sz / 2)
    {
      veca.push_back(func[2 * i]);
      vecb.push_back(func[2 * i + 1]);
    }
    dft(veca, inverse);
    dft(vecb, inverse);
    complex<double> now = 1, zeta = polar(1.0, inverse * 2.0 * acos(-1) / sz);
    rep(i, sz)
    {
      func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
      now *= zeta;
    }
  }

public:
  template <typename T>
  static vector<double> multiply(vector<T> f, vector<T> g)
  {
    vector<complex<double>> nf, ng;
    int sz = 1;
    while (sz < f.size() + g.size())
      sz *= 2;
    nf.resize(sz);
    ng.resize(sz);
    rep(i, f.size())
    {
      nf[i] = f[i];
      ng[i] = g[i];
    }
    dft(nf, 1);
    dft(ng, 1);
    rep(i, sz) nf[i] *= ng[i];
    dft(nf, -1);
    vector<double> res;
    rep(i, sz) res.push_back(nf[i].real() / sz);
    return res;
  }
};
int main()
{
  //https://atcoder.jp/contests/atc001/tasks/fft_c
  ll n;
  cin >> n;
  vector<ll> v, u;
  rep(i, n)
  {
    ll a, b;
    cin >> a >> b;
    v.push_back(a);
    u.push_back(b);
  }
  //v,uは同じ要素数にする
  FastFourierTransform a;
  auto k = a.multiply(v, u);
  rep(i, n * 2) cout << (i == 0 ? 0 : (ll)(k[i - 1] + 0.01)) << endl;
  return 0;
}