#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
ll table[n]={};
ll mai;
ll a,b=0,ko=0;
rep(i,n) {
    cin >> a;
    if(a==0){
        ko++;
    }
    else {
        if(ko==0){
            table[b]=a;
            b++;
        }
        else{
            table[b]=ko*-1;
            ko=0;b++;
            table[b]=a;
            b++;
        }
    }
}
if(ko!=0){
    table[b]=ko*-1;
    b++;
    ans+=ko*(ko-1)/2;
}

/*  for (int i = 0; i < b; ++i) {
    cout << table[i] << " ";
}cout  << endl; */
ll temp; 

ll bai,sum;

rep(i,b-1){
 //   cout << ans <<' ';
    if(table[i]>0){
        sum=table[i];
        bai=1;
    }
    else{
        ans+=table[i]*(table[i]+1)/2;
        bai=table[i]*-1;
        sum=0;
    }
    for(int k=i+1;k<b;k++){
       // cout << ans <<' ';
        if(table[k]<0){
            ans-=table[k]*bai;
            continue;
        }
        temp=sum^table[k];
        if(temp==(sum|table[k])){
            ans+=bai;
            sum=temp;
        }
        else break;
    }
}
ans+=n;

cout << ans << endl;
return 0;
}



