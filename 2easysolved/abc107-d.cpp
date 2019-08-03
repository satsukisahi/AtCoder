#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
struct SegTree
{
    private:
        ll n;
        vector<ll> node;
    public:
        SegTree(vector<ll> v){
            node.resize((1LL<<64-__builtin_clzll(v.size()))*2-1,0);//最小値なので残りはINFで埋める
            n=1LL<<64-__builtin_clzll(v.size());
            for(ll i=0; i<v.size(); i++) node[i+n-1] = v[i];//最下段から構築
            for(ll i=n-2; i>=0; i--) node[i] = node[2*i+1]+ node[2*i+2];
        }

    void update(ll x, ll val) {
    x += (n - 1);// 最下段index
    node[x] += val;
    while(x > 0) {
        x = (x - 1) / 2;
        node[x] = node[2*x+1]+ node[2*x+2];
    }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える k := 自分がいるノードのインデックス 対象区間は [l, r) にあたる
    ll getmin(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;
    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l) return 0;
    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];
    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return vl+ vr;
    }
};
int main()
{
ll n ;
cin >> n ;
vector<ll> v(n);
rep(i, n){
  cin >> v[i];
}
ll lower=0,upper=1e+9;
ll seenow;
bool ok2butan;
while(true){
seenow=(lower+upper)/2;

//todo:seenowに対して処理
vector<ll> s;
s.push_back(0);
rep(i,n){
  if(seenow>=v[i])s.push_back(-1+s[i]);
  else s.push_back(1+s[i]);
}
ll sum=0;
vector<ll> t(200200);
SegTree ss(t);
rep(i,n){
  ss.update(s[i]+100100,1);
  sum+=ss.getmin(0,s[i+1]+100100+1);
}
if(sum<(n*(n+1)+3)/4)ok2butan=true;
else ok2butan=false;
//条件を満たすならok2butan=trueにする

if(ok2butan){
    upper=seenow;
    if(upper==lower+1){ans=seenow;break;}
    }
else {
    lower=seenow;
    if(upper==lower+1){ans=seenow+1;break;}
    }
//cout << seenow << endl;

}
cout << ans << endl;
return 0;
}
