#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(void)
{
int n=17;
int table[n];
int maxi=0;
// 入力
for(int i=0; i<n; i++){
    cin >> table[i];
}
//最大値を求める
for(int i=0; i<n; i++){
    if(maxi<table[i]){maxi=table[i];}
}
vector<pair<int, int> > pairs(maxi);
for(int i=0; i<n; i++){
    pairs[table[i]].first=table[i];
    pairs[table[i]].second++;

}
// b順にソート
sort(pairs.begin(),pairs.end(), compare_by_b);

//最頻値はpairs[maxi].first 回数はpairs[maxi].second
for(int i=0; i<maxi; i++){
    cout << pairs[i].first << " "<<pairs[i].second << endl;
}
return 0;
}
    

