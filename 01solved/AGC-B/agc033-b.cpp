#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;
ll h,w,n;

bool in(ll x,ll y){
    return (x>=0&&y>=0&&x<w&&y<h);
}
int main()
{ 

cin >> h>>w>>n; 
ll r,c;
cin >> r>>c; 
string s,t;
cin >> s>>t; 

ll now=c;
rep(i,n){
    if(s[i]=='R')now++;
    if(now>w){
        cout << "NO" << endl;
        return 0;
    }
    if(t[i]=='L'&&now>1)now--;
}
now=c;
rep(i,n){
    if(s[i]=='L')now--;
    if(now<1){
        cout << "NO" << endl;
        return 0;
    }
    if(t[i]=='R'&&now<w)now++;
}
now=r;
rep(i,n){
    if(s[i]=='U')now--;
    if(now<1){
        cout << "NO" << endl;
        return 0;
    }
    if(t[i]=='D'&&now<h)now++;
}
now=r;
rep(i,n){
    if(s[i]=='D')now++;
    if(now>h){
        cout << "NO" << endl;
        return 0;
    }
    if(t[i]=='U'&&now>1)now--;
}

cout << "YES" << endl;
return 0;
} 