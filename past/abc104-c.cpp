#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main()
{
ll ans=100000,d,g;
cin >> d>>g;
ll que[d];
ll comp[d];
rep(i,d){
    cin >>que[i]>>comp[i];
}
//bit全探索
for(int i=0;i< (1<<d);i++){
    ll sco=0,q=0,dd;
    rep(j,d){
        if(i>>j&1){sco+=(j+1)*100*que[j]+comp[j];q+=que[j];}
    }
    //解いてない中で最も高得点問題を探す
    for(ll j = d-1; j >=0 ; j--){
        if(sco>=g)break;
        if(!(i>>j&1)){dd=j;break;}
    }
    //cout << q <<' '<<sco<<' '<<dd<<' ';
    //解いてない中で最も高得点問題を目標まで解く
    rep(i,que[dd]){
        if(sco>=g)break;
        sco+=(dd+1)*100;
        q++;
    }
    //cout << q <<' '<<sco<< endl;
    if(ans>q&&sco>=g)ans=q;
}


cout << ans << endl;
return 0;
}



