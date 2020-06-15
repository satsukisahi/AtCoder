#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 9223372036854775807; //MAX 9223372036854775807

int main()
{
ll t ;
cin >> t ;
rep(i,t){
  ll n ;
  cin >> n ;
  ll a , b , c , d ;
  cin >> a >> b >> c >> d ;
  map<ll,ll> m;
  m[0]=INF;
  queue<ll> q;
  q.push(n);
  m[n]=1;
  while(!q.empty()){
    ll p=q.front();
    q.pop();
    if(m[p/2]==0||m[p/2]>m[p]+a+(p%2)*d ){
      m[p/2]=m[p]+a+(p%2)*d;
      q.push(p/2);
    }
    if(m[p/3]==0||m[p/3]>m[p]+b+(p%3)*d ){
      m[p/3]=m[p]+b+(p%3)*d;
      q.push(p/3);
    }
    if(m[p/5]==0||m[p/5]>m[p]+c+(p%5)*d ){
      m[p/5]=m[p]+c+(p%5)*d;
      q.push(p/5);
    }
    if(m[(p+1)/2]==0||m[(p+1)/2]>m[p]+a+(2-p%2)*d ){
      m[(p+1)/2]=m[p]+a+(2-p%2)*d;
      q.push((p+1)/2);
    }
    if(m[(p+2)/3]==0||m[(p+2)/3]>m[p]+b+(3-p%3)*d ){
      m[(p+2)/3]=m[p]+b+(3-p%3)*d;
      q.push((p+2)/3);
    }
    if(m[(p+4)/5]==0||m[(p+4)/5]>m[p]+c+(5-p%5)*d ){
      m[(p+4)/5]=m[p]+c+(5-p%5)*d;
      q.push((p+4)/5);
    }
    if(p/2==0)m[0]=min(m[0],m[p]+(p%2)*d);
    if(p/3==0)m[0]=min(m[0],m[p]+(p%3)*d);
    if(p/5==0)m[0]=min(m[0],m[p]+(p%5)*d);
    if(p<INF/d)m[0]=min(m[0],m[p]+p*d);
  }
  cout << m[0]-1 << endl;
}

return 0;
}