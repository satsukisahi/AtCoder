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
int ans=1000000;
//整数値の入力
int n,a,b,c;
cin >> n>> a>> b>> c;
int table[n]={};


for (int i = 0; i < n; ++i) {
    cin >> table[i];
}
for (int i1 = 0; i1 < 4; ++i1) {
for (int i2 = 0; i2 < 4; ++i2) {
for (int i3 = 0; i3 < 4; ++i3) {
for (int i4 = 0; i4 < 4; ++i4) {
for (int i5 = 0; i5 < 4; ++i5) {
for (int i6 = 0; i6 < 4; ++i6) {
for (int i7 = 0; i7 < 4; ++i7) {
for (int i8 = 0; i8 < 4; ++i8) {
//int i1=2,i2=1,i3=1,i4=1,i5=0,i6,i8,i7;
int take[4]={};
int kaisu[4]={};
if(n>0){take[i1]+=table[0];kaisu[i1]++;}
if(n>1){take[i2]+=table[1];kaisu[i2]++;}
if(n>2){take[i3]+=table[2];kaisu[i3]++;}
if(n>3){take[i4]+=table[3];kaisu[i4]++;}
if(n>4){take[i5]+=table[4];kaisu[i5]++;}
if(n>5){take[i6]+=table[5];kaisu[i6]++;}
if(n>6){take[i7]+=table[6];kaisu[i7]++;}
if(n>7){take[i8]+=table[7];kaisu[i8]++;}

if(kaisu[0]*kaisu[1]*kaisu[2]!=0){
   //sort(table,table+3);
   int temp;
   temp=(kaisu[0]+kaisu[1]+kaisu[2]-3)*10+abs(take[0]-c)+abs(take[1]-b)+abs(take[2]-a);
   if(temp<ans){ans=temp;}
  // cout << a<<b<<c<< " " << kaisu[0]<<kaisu[1]<<kaisu[2]<<" "<<take[0]<<take[1]<<take[2]<<endl;
}


}}}}}}}}
//回答
cout << ans << endl;
return 0;
}

