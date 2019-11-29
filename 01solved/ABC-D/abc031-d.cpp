#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807

ll mypow(ll a,ll b){
    ll res=1;
    a%=mo;
    while(b){
        if(b&1)
            res=res*a%mo;
        a=a*a%mo;
        b>>=1;
    }
    return res;
}

void digit(ll x,ll y,ll *a,ll k){
    a[k]=x%y;
    if(x>=y)digit( (x-x%y)/y , y , a , k+1 );
}

int main()
{
ll k,n;
cin >> k>>n;

string t[n][2] = {};
rep(i, n){
    cin >> t[i][0]>> t[i][1];
}
ll dig[10]={};

rep(i,mypow(3,k)){
    vector<string> v(k,"A");
    digit(i, 3 ,dig ,0);
    bool ok=1;
    rep(j,n){//各文について
        ll st=0;
        rep(l,(int)(t[j][0].length())){
            int ii=t[j][0][l]-'0';
            ii--;
            if(v[ii]=="A"){
                if(t[j][1].length()<st+dig[ii]+1){ok=0;break;}
                v[ii]=t[j][1].substr( st, dig[ii]+1);
                st+=dig[ii]+1;
            }
            else{
                if(v[ii]==t[j][1].substr( st, dig[ii]+1))st+=dig[ii]+1;
                else{
                    ok=0;break;
                }
            }
        }
        if(st!=t[j][1].length())ok=0;
    if(!ok)break;
    }
    if(ok){
        for (int i = 0; i < k; ++i) {
            cout << v[i] << endl;;
        }
        break;
    }
}
return 0;
}
