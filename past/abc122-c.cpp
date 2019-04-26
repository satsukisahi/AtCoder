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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
ll ans,n,q;
string s;

cin >> n>>q;
cin >> s;

int len=(int)(s.length());
int table[len]={0};
rep(i,n-1) {
    if(s[i]=='A'&&s[i+1]=='C'){
        if(i==0)table[i]=1;
        else table[i]=table[i-1]+1;
    }
    else {
        if(i==0)table[i]=0;
        else table[i]=table[i-1];
    }
}
/* for (int i = 0; i < n; ++i) {
    cout << table[i] << " ";
}cout  << endl; */

rep(i,q){
    int l,r,aa;
    cin >> l>>r;
    if(l-2<0)aa=0;
    else aa=table[l-2];
    cout <<table[r-2]-aa << endl;
}



return 0;
}



