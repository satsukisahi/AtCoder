#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1 << 30;
ll ans = 0;
ll tim[289]={};
int main()
{
ll n;
cin >> n;
string t[n] = {};
rep(i, n)
{
    cin >> t[i];
}
rep(i,n){
    ll st,en;
    st=stoll(t[i].substr( 0, 2))*60+stoll(t[i].substr( 2, 2));
    en=stoll(t[i].substr( 5, 2))*60+stoll(t[i].substr( 7, 2));
    tim[st/5]++;
    tim[(en-1)/5+1]--;
}
rep1(i,289){
    tim[i]+=tim[i-1];
}
bool a=0;
rep(i,289){
    if(tim[i]>0&&!a){
        a=1;
        cout << std::setfill('0') << std::right << std::setw(2)<<i/12<<std::setfill('0') << std::right << std::setw(2)<<(i%12)*5 << '-';
    }
    if(tim[i]==0&&a){
        a=0;
        cout  <<std::setfill('0') << std::right << std::setw(2)<< i/12<<std::setfill('0') << std::right << std::setw(2)<<(i%12)*5<< endl;
    }
}

/* for (int i = 0; i < 289; ++i) {
    cout << tim[i] << " ";
}cout  << endl; */


return 0;
}