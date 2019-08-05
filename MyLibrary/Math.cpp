#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
// 累乗a^b
ll mypow(ll a, ll b){
  ll res = 1;
  a %= mo;
  while (b)
  {
    if (b & 1)
      res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
//素数判定
bool prime(int num){
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}
//約数
vector<ll> divisor(ll n){
  vector<ll> div;
  for (int i = 1; i*i <= n; i++)
  {
    if (n % i == 0)
    {
      div.push_back(i);
      if(n/i!=i)div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return div;
}
//素因数分解
map<ll,ll> primefactor(ll n){
  map<ll,ll> div;
  ll nn=n;
  for (int i = 2; i*i <= nn; i++)
  {
    if (n % i == 0)
    {
      div[i]++;
      n/=i;
      i--;
    }
  }
  return div;
}
//階乗
vector<ll> factorial(ll n){
  vector<ll> fac;
  fac.push_back(1);
  for(ll i = 1; i < 100000; i++){
      fac.push_back((fac[i-1]*i)%mo);
  }
  return fac;
}
//二項係数mod
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//行列クラス
template <class T>
struct Matrix
{
  vector<vector<T>> A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}

  Matrix(size_t n) : A(n, vector<T>(n, 0)){};

  size_t height() const
  {
    return (A.size());
  }

  size_t width() const
  {
    return (A[0].size());
  }

  inline const vector<T> &operator[](int k) const
  {
    return (A.at(k));
  }

  inline vector<T> &operator[](int k)
  {
    return (A.at(k));
  }

  static Matrix I(size_t n)
  {
    Matrix mat(n);
    for (int i = 0; i < n; i++)
      mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B)
  {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B)
  {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B)
  {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector<vector<T>> C(n, vector<T>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k)
  {
    Matrix B = Matrix::I(height());
    while (k > 0)
    {
      if (k & 1)
        B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const
  {
    return (Matrix(*this) += B);
  }

  Matrix operator-(const Matrix &B) const
  {
    return (Matrix(*this) -= B);
  }

  Matrix operator*(const Matrix &B) const
  {
    return (Matrix(*this) *= B);
  }

  Matrix operator^(const long long k) const
  {
    return (Matrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, Matrix &p)
  {
    size_t n = p.height(), m = p.width();
    for (int i = 0; i < n; i++)
    {
      os << "[";
      for (int j = 0; j < m; j++)
      {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }

  T determinant()
  {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for (int i = 0; i < width(); i++)
    {
      int idx = -1;
      for (int j = i; j < width(); j++)
      {
        if (B[j][i] != 0)
          idx = j;
      }
      if (idx == -1)
        return (0);
      if (i != idx)
      {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for (int j = 0; j < width(); j++)
      {
        B[i][j] /= vv;
      }
      for (int j = i + 1; j < width(); j++)
      {
        T a = B[j][i];
        for (int k = 0; k < width(); k++)
        {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};


int main()
{
ll c;
//累乗
mypow(3, 5); //243

//最大公約数
__gcd(21, 35); //7


//素数判定
prime(103);//true
//約数
vector<ll> v=divisor(24);//1,2,3,4,6,8,12,24

//素因数分解 値,個数
map<ll,ll> p=primefactor(735134400);
for (auto i = p.begin(); i != p.end(); ++i) {
  cout << "val" << i->first << "count" << i->second << endl;
}

//階乗
vector<ll> fac=factorial(100000);
fac[6];//720

//二項係数mod
COMinit();//前処理
COM(7, 3);//35

//辞書順で次の順列
ll array[3]={2,1,3};
next_permutation(array, array + 3);//array={2,3,1};

//行列クラス modや定数倍などは適宜自分で追加
Matrix<ll> a(2);a[0][0]=1;a[0][1]=2;a[1][0]=3;a[1][1]=4;
cout << a << endl;
Matrix<ll> b(2);
b=a+a;
cout << b << endl;
b=a^2;
cout << b << endl;

return 0;
}
