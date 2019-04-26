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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main()
{
ll ans,n,x;
ans=0;
cin >> n>>x;
ll pa[51]={};
ll ban[51]={};
ll sum[51]={};
sum[0]=1;
pa[0]=1;
for(ll i = 1; i <51; i++){
    pa[i]=1+pa[i-1]*2;
    ban[i]=2+ban[i-1]*2;
    sum[i]=pa[i]+ban[i];
}
//cout << pa[n] << endl;
for(ll i = n; i >=0; i--){
    if(i==0){ans+=1;break;}
    if(sum[i]/2+1<x){
        ans+=pa[i-1]+1;
        x-=sum[i-1]+2;
    }
    else if(sum[i]/2+1==x){
        ans+=pa[i-1]+1;
        break;
    }
    else if(sum[i]/2==x){
        ans+=pa[i-1];
        break;
    }
    else{
        x-=1;
    }
  // cout <<i<<" " <<x<<" "<<ans << endl;
    if(x==0)break;
    
    
}
cout << ans << endl;
return 0;
}



