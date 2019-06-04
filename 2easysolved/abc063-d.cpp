#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
ll n,a,b;
cin >> n>>a>>b;
ll h[n] = {};
rep(i, n)
{
    cin >> h[i];
}
sort(h,h+n);
int lower=0,upper=h[n-1];
int seenow,oklowest;
bool ok2butan;
while(true){
seenow=(lower+upper)/2;

//todo:seenowに対して処理
//条件を満たすならok2butan=trueにする
ok2butan=true;
ll count=0;
rep(i,n){
    if(h[i]-b*seenow>0)count+=(h[i]-b*seenow-1)/(a-b)+1;
    if(count>seenow){ok2butan=false;break;}
}


if(ok2butan){
    upper=seenow;
    if(upper==lower+1){oklowest=seenow;break;}
    }
else {
    lower=seenow;
    if(upper==lower+1){oklowest=seenow+1;break;}
    }
}

cout << oklowest << endl;
return 0;
}