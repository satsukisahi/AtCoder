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


int main()
{
char n[200010];
cin >> n;
char m[200010];
cin >> m;
bool ans=0;

pair<char, char> id[27];
id[0].first = m[0];
id[0].second =n[0];
int syu=1;
int size=strlen( n );
bool flag=1;
//cout << size << endl;
for(int i=1;i<size;++i){
    //cout << n[i]<<" "<<m[i] <<syu<< endl;
    for(int j=0;j<syu;++j){
        if(id[j].first==m[i]){
            flag=0;
            if(id[j].second!=n[i]){ans=1;}
        }
        if(id[j].second==n[i]){
            flag=0;
            if(id[j].first!=m[i]){ans=1;}
        }

    }
    if(flag){id[syu].first = m[i];id[syu].second =n[i];syu++;}
    flag=1;
}

//回答
string ans1;
if(ans){ans1="No";}
else{ans1="Yes";}
cout << ans1 << endl;
return 0;
}