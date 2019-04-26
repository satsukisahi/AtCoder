#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll v[250001][4];
ll root[250001][2];

int main()
{
ll h,w;

cin >> h>>w;
int table[h][w]={};
rep(i,h)rep(j,w){
    cin >> table[i][j];
}

rep(i,h)rep(j,w){
    if(i%2==0){
    root[j+i*w][0]=i;
    root[j+i*w][1]=j;}
    else{
    root[j+i*w][0]=i;
    root[j+i*w][1]=w-j-1;}
}

ll coun=0;
rep(i,h*w-1){
    if(table[root[i][0]][root[i][1]]%2==1){
        table[root[i][0]][root[i][1]]--;
        table[root[i+1][0]][root[i+1][1]]++;
        v[coun][0]=root[i][0];
        v[coun][1]=root[i][1];
        v[coun][2]=root[i+1][0];
        v[coun][3]=root[i+1][1];
        coun++;
    }
}

cout << coun << endl;
rep(i,coun){
cout << v[i][0]+1<<' ' <<v[i][1]+1<<' ' <<v[i][2]+1<<' ' <<v[i][3]+1 << endl;
}
return 0;
}

