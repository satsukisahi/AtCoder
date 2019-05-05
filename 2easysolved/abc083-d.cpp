#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(ll i = 1; i < (ll)(n); i++)
const ll mo=1000000007;
const ll INF=1<<30;
ll ans=0;


int main()
{ 
string s;
cin >> s; 
vector<ll> v;
ll tem=1;
rep(i,s.size()-1){
    if(s[i]==s[i+1])tem++;
    else {v.push_back(tem);tem=1;}
}
v.push_back(tem);
if(v.size()==1){
    cout << s.size() << endl;
    return 0;
}
if(v.size()==2){
    cout << max(v[0],v[1]) << endl;
    return 0;
}

int l=v[0];
int r=v[v.size()-1];
int ll=0;
int rr=v.size()-1;


for(int aaa = 0; aaa < v.size()-2; aaa++){
    if(l>=r){
        r=r+v[rr-1];
        rr--;
    }
    else{
        l=l+v[ll+1];
        ll++;
    }
}

cout << max(l,r) << endl;
return 0;
} 