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
//整数値の入力
int n;
cin >> n;
tuple<int, int, int> data[n];
//xy高さ

for (int i = 0; i < n; ++i) {
     int x, y,h;
        cin >> x >> y >> h;
        data[i] = make_tuple(x, y, h);
}

int ans[3]={};

for (int x = 0;x<101;++x){
    for (int y = 0;y<101;++y){

        int  p, q, h,maxh;

        for(int i=0;i<n;++i){
            tie(p, q, h) = data[i];
            if(h>0){maxh=h+abs(x-p)+abs(y-q);}
        }
        bool hantei=1;
        
        for(int i=0;i<n;++i){
            tie(p, q, h) = data[i];
            int temp;
            temp=max(maxh-abs(x-p)-abs(y-q),0);
            if(temp!=h){hantei=0;}
        }
        if(hantei){ans[0]=x;ans[1]=y;ans[2]=maxh;}
    }
}
//回答
cout << ans[0] << " "<<ans[1] <<" "<<ans[2]<< endl;
return 0;
}