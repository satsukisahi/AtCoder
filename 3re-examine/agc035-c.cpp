#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


int main()
{
ll n;
cin >> n;
ll ch=1;
rep(i,20){
    if(n==ch){
    cout << "No" << endl;
    return 0;
    }
    else if(ch>n)break;
    else ch*=2;
}
ll a=ch/2;
ch=4;

cout << "Yes" << endl;
rep(i,ch-2){
    cout << i+1 << " " << i+2 << endl;
}
cout << ch-1 << " " << 1+n << endl;
rep(i,ch-2){
    cout << i+1+n << " " << i+2+n << endl;
}

if(n%2){
    rep(i,(n-ch+1)/2){
        cout << 1 << " " << ch+2*i << endl;
        cout << ch+2*i << " " << ch+2*i+1 << endl;
        cout << 1 << " " << ch+2*i+1+n << endl;
        cout << ch+2*i+n+1 << " " << ch+2*i+n << endl;
    }
}
else{
    rep(i,(n-ch)/2){
        cout << 1+n << " " << ch+2*i << endl;
        cout << ch+2*i << " " << ch+2*i+1 << endl;
        cout << 1+n << " " << ch+2*i+1+n << endl;
        cout << ch+2*i+n+1 << " " << ch+2*i+n << endl;
    }
    cout << a << " " << n << endl;
    if(n-a+1==3)cout << 3 << " " << n+n << endl;
    else cout << n+n-a+1 << " " << n+n << endl;
}
return 0;
}
