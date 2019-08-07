#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
ll mo;
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
          {C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
          C[i][j]%=mo;}
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
int main()
{
ll l ;
cin >> l ;
ll a , b  ;
cin >> a >> b >> mo ;
ll keta[19]={};
ll su=0,te=10;
rep(i,19){
  if(a+b*su>=te){te*=10;continue;}
  keta[i]=(te-1-a-b*su)/b+1;
  su+=keta[i];
  if(su>l){keta[i]-=su-l;break;}
  te*=10;
}
su=0;
rep(i,19){
  if(keta[i]==0)continue;
  if(keta[i]==1){ans=ans*mypow(10,i+1);ans+=(a+b*su)%mo;su++;ans%=mo;continue;}
  Matrix<ll> aa(3);aa[0][0]=mypow(10,i+1);aa[0][1]=1;aa[0][2]=0;
                  aa[1][0]=0;aa[1][1]=1;aa[1][2]=b%mo;
                  aa[2][0]=0;aa[2][1]=0;aa[2][2]=1;
  Matrix<ll> bb(3);
  bb=aa^(keta[i]-1);
  ans=ans*mypow(mypow(10,i+1),keta[i])%mo;
  ans%=mo;
  ans+=(bb[0][0]*((a+b*su)%mo) + bb[0][1]*((a+b*(su+1))%mo) +bb[0][2])%mo;
  su+=keta[i];
}

cout << ans%mo << endl;
return 0;
}
