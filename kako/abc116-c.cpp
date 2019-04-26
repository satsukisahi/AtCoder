#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
int n,l;
int i=0;
cin >> n;
int table[n+1]={};
for (int i = 0; i < n; ++i) {
    cin >> table[i];
}



int max=0,count=0;

for(i=0;i<n;++i){
    if(max<table[i])
    max=table[i];
}

while(max!=0){
    for(i=0;i<n;++i){
        if(max==table[i]){
            if(table[i]==table[i+1])table[i]=table[i]-1;
            else {table[i]=table[i]-1;count++;}
        }
    }
    max--;
}

cout << count<< endl;
return 0;
}