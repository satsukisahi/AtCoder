#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
ll mo=1000000007,ans=0;
ll dp[0][0];

int main()
{
ll n,q;

cin >> n>>q;
string s;
cin >> s;
s='z'+s+'z';
char t[q];
char d[q];
rep(i,q) {
    cin >> t[i]>>d[i];
}
char now;
int ichi,syo,sita=0,ue=0;

//二分探索でichiを指定
int x=0,z=n+1;
while(true){
syo=(x+z)/2;
ichi=syo;
//cout << syo<<' ';
now=s[ichi];
rep(i,q){
    if(now==t[i]){
        if(d[i]=='L'){now=s[ichi-1];ichi--;}
        else{now=s[ichi+1];ichi++;}
        //cout << now<<' ';
        
    }
}
if(ichi==0){
    x=syo;
    if(x==z-1){sita=syo;break;}
    }
else {
    z=syo;
    if(x==z-1){sita=syo-1;break;}
    }
}
//二分探索でichiを指定
x=0;
z=n+1;
while(true){
syo=(x+z)/2;
ichi=syo;
//cout << syo<<' ';
now=s[ichi];
rep(i,q){
    if(now==t[i]){
        if(d[i]=='L'){now=s[ichi-1];ichi--;}
        else{now=s[ichi+1];ichi++;}
        //cout << now<<' ';
        
    }
}
if(ichi!=n+1){
    x=syo;
    if(x==z-1){ue=syo+1;break;}
    }
else {
    z=syo;
    if(x==z-1){ue=syo;break;}
    }
}

ans=-sita+ue-1;
cout << ans << endl;
return 0;
}



