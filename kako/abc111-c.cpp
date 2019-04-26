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

//配列を投げたら最頻値の値と個数を返す（2番まで）
vector<int> mode(int table[],int n){
    int count[100010]={};
    for(int i=0;i<n;++i){
        count[table[i]]++;
    }
    int max1=0,max2=0,cnt1=0,cnt2=0;
    for(int i=0;i<100010;++i){
        if(cnt1<count[i]){
            max2=max1;cnt2=cnt1;cnt1=count[i];max1=i;
            }
        else if(cnt2<count[i]){cnt2=count[i];max2=i;}
    }
    return {max1,cnt1,max2,cnt2};
}


int main()
{
//回答が整数の場合
int ans;
//整数値の入力
int n;
cin >> n;
//行列の入力
int table1[n/2]={};
int table2[n/2]={};
for (int i = 0; i < n/2; ++i) {
    cin >> table1[i];
    cin >> table2[i];
}


vector<int>vec1=mode(table1,n/2);
vector<int>vec2=mode(table2,n/2);


//最頻値同じ場合
if(vec1[0]==vec2[0]){
ans=min(n-vec1[1]-vec2[3],n-vec1[3]-vec2[1]);
}
else{
    ans=n-vec1[1]-vec2[1];
}

//回答
cout << ans << endl;
return 0;
}