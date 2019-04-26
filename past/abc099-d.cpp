#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];
int summ(ll num){
    string ss;
    ll su=0;
    ss=to_string(num);
    int len=(int)(ss.length());
    rep(i,len){
        string str1(ss, i,1);
        su+=stoll(str1);
    }
    return su;
}
int main()
{
ll n;
cin >> n;
string s;
ll num=0;
ll a=1;
ll nine=0;
ll num1,num2;
ll max=0;
while(num<n){
    num1=a;
    num2=a+1;
    rep(i,nine){
        num1=num1*10+9;
        num2=num2*10+9;
    }
    if(double(num1)/summ(num1)>double(num2)/summ(num2)){
        nine++;
        a=1;
        continue;
    }
    a++;
    if(num1<=max)continue;
    cout << num1 << endl;
    num++;
    max=num1;
  //  cout << summ(4685456) << endl;
   // cout << double(99)/summ(99)<<' '<<double(109)/summ(109) << endl;
}
return 0;
}
