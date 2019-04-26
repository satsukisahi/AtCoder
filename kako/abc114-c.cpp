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
int ans=0;

void check(int n,int num){
    
    
        //357がひとつ以上あればカウント
        bool san=0;
        bool go=0;
        bool nana=0;
        string str = to_string(num);
        for(int i = 0; i < (int)str.size(); ++i){
            if(str[i]=='3'){san =true;}
            if(str[i]=='5'){go  =true;}
            if(str[i]=='7'){nana=true;}
        }
        if(san&&go&&nana){ans++;}

        if(10*(double)num+3<=n){check(n,10*num+3);}
        if(10*(double)num+5<=n){check(n,10*num+5);}
        if(10*(double)num+7<=n){check(n,10*num+7);}

    

}

int main()
{

//整数値の入力
int n;
cin >> n;
int i;


check(n,3);
check(n,5);
check(n,7);



//回答
cout <<ans<< endl;
return 0;
}