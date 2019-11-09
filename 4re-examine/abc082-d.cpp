#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;
bool v[16020];
bool vv[16020];

int main()
{ 
string s;
cin >> s; 
ll x,y;
cin >> x>>y;
vector<ll> xx;
vector<ll> yy;
ll temp=0;
bool xy=0;
rep(i,s.size()){
    if(s[i]=='F')temp++;
    else break;
}
x=x-temp;
ll a=temp;
temp=0;
for(ll i = a; i < (ll)(s.size()); i++){
    if(s[i]=='F')temp++;
    else{
        if(xy){
            if(temp!=0)yy.push_back(temp);
            xy=0;
            temp=0;
        }
        else{
            if(temp!=0)xx.push_back(temp);
            xy=1;
            temp=0;
        }
    }
} 
if(temp!=0){
    if(xy)yy.push_back(temp);
    else xx.push_back(temp);
}

if(xx.size()==0){
    if(x!=0){
        cout << "No" << endl;
        return 0;
    }
}
else{
    rep(i,16020){
        v[i]=false;
        vv[i]=false;
    }
    v[0+8010]=true;
    rep(i,xx.size()){rep(j,16020){
        if(v[j]){
            vv[j+xx[i]]=true;
            vv[j-xx[i]]=true;
        }
    }
    rep(j,16020){
        v[j]=vv[j];
        vv[j]=false;
    }
    }
    if(!v[x+8010]){
        cout << "No" << endl;
        return 0;
    }
}

if(yy.size()==0){
    if(y!=0){
        cout << "No" << endl;
        return 0;
    }
}
else{
    rep(i,16020){
        v[i]=false;
        vv[i]=false;
    }
    v[0+8010]=true;
    rep(i,yy.size()){rep(j,16020){
        if(v[j]){
            vv[j+yy[i]]=true;
            vv[j-yy[i]]=true;
        }
    }
    rep(j,16020){
        v[j]=vv[j];
        vv[j]=false;
    }
    }
    if(!v[y+8010]){
        cout << "No" << endl;
        return 0;
    }
}


cout << "Yes" << endl;
return 0;
} 