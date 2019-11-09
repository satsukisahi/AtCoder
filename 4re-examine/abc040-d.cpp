#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
struct UnionFind
{
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) {}
    bool unionSet(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y)
    {
        return root(x) == root(y);
    }
    ll root(ll x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(ll x)
    {
        return -data[root(x)];
    }
};

struct info
{
    ll a,b,y;
};
bool cmp(const info &a, const info &b)
{
    return a.y > b.y;
}
struct info2
{
    ll p,y,i,ans;
};
bool cmp2(const info2 &a, const info2 &b)
{
    return a.y > b.y;
}
bool cmp3(const info2 &a, const info2 &b)
{
    return a.i < b.i;
}

//UnionFind arr(n);で０～n-1バラバラが生成
//arr.findSet(x,y)同じ集合か
//arr.size(x)xが属す要素の個数
//arr.unionSet(x,y)xが属す集合とyが属す集合をマージ
int main()
{
ll n,m;
cin >> n>>m;
info t[m] = {};
rep(i, m)
{
    cin >> t[i].a>> t[i].b>> t[i].y;
}
ll q;
cin>>q;
info2 tt[q] = {};
rep(i, q)
{
    cin >> tt[i].p>> tt[i].y;
    tt[i].i=i;
}
UnionFind arr(n+1);
sort(t,t+m,cmp);
sort(tt,tt+q,cmp2);
ll k=0;
rep(i,q){
    while(k!=m&&t[k].y>tt[i].y){
        arr.unionSet(t[k].a,t[k].b);
        k++;
    }
    tt[i].ans=arr.size(tt[i].p);
}
sort(tt,tt+q,cmp3);
rep(i,q){
cout << tt[i].ans << endl;
}
return 0;
}
