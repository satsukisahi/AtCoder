#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
double ans = 0,ans2=0;


void comb(vector<vector<long long int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int k = 1; k < v.size(); k++)
    {
        for (int j = 1; j < k; j++)
        {
            v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
        }
    }
}

int main()
{
ll n,a,b;
cin >> n>>a>>b;
ll v[n] = {};
rep(i, n)
{
    cin >> v[i];
}
sort(v, v+n);
rep(i,a){
    ans+=v[n-1-i];
}
ans/=a;


vector<vector<long long int> > vv(n+1,vector<long long int>(n+1,0));
comb(vv);
ll re=v[n-a];
auto itr1 = lower_bound(v,v+n, re);
auto itr2 = upper_bound(v,v+n, re);
ll aaa=itr2-itr1;
if(v[n-a]==v[n-1]){
    for(ll i=a;i<min(b+1,aaa+1);i++){
        ans2+=vv[itr2-itr1][i];
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    cout <<fixed<<setprecision(0)<< ans2 << endl;
    return 0;
}



ll te=v+n-itr2;
//cout << a-te<<" "<<itr2-itr1 << endl;
ans2=vv[itr2-itr1][a-te];

cout<<fixed<<setprecision(10)<<ans<<endl;
cout <<fixed<<setprecision(0)<< ans2 << endl;
return 0;
}
