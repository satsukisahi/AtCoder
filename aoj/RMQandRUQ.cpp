#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

//子から親を求める演算
auto calc_parent = [](ll x, ll y) { return min(x,y); };
//親遅延配列を子に伝播する演算
auto calc_lazychild = [](ll &x,ll y) { x=y; };
//遅延配列をノードに反映する演算
auto lazy_to_node = [](ll &x,ll y) { x=y; };
//遅延配列に値を入れる演算 y-値 l,r-区間index
auto intolazy = [](ll &x,ll y,ll r,ll l) { x=y; };
//単位元
const ll unit = INF;

struct LazySegTree
{
private:
  ll n;
  vector<ll> node,lazy;
  vector<bool> islazy;

public:
  LazySegTree(vector<ll> v)
  {
    node.resize((1LL << 64 - __builtin_clzll(v.size())) * 2 - 1, unit); 
    lazy.resize((1LL << 64 - __builtin_clzll(v.size())) * 2 - 1, unit); 
    islazy.resize((1LL << 64 - __builtin_clzll(v.size())) * 2 - 1, 0); 

    n = 1LL << 64 - __builtin_clzll(v.size());
    for (ll i = 0; i < v.size(); i++)
      node[i + n - 1] = v[i]; //最下段から構築
    for (ll i = n - 2; i >= 0; i--)
      node[i] = calc_parent(node[2 * i + 1], node[2 * i + 2]);
  }
  
  // k 番目のノードについて遅延評価を行う
  void eval(int k, int l, int r){ 
    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
    if (islazy[k]){
      lazy_to_node(node[k],lazy[k]);
      // 最下段かどうかのチェック
      if (r - l > 1){
        calc_lazychild(lazy[2 * k + 1],lazy[k]);
        calc_lazychild(lazy[2 * k + 2],lazy[k]);
        islazy[2 * k + 1] = 1;
        islazy[2 * k + 2] = 1;
      }
      // 伝播が終わったので、自ノードの遅延配列を空にする
      islazy[k] = 0;
      lazy[k] = unit;
    }
  }

  void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1){
    if (r < 0)
      r = n;
    // k 番目のノードに対して遅延評価を行う
    eval(k, l, r);
    // 範囲外なら何もしない
    if (b <= l || r <= a)
      return;
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
    if (a <= l && r <= b){
      intolazy(lazy[k],x,r,l);
      islazy[k] = 1;
      eval(k, l, r);
    }
    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
    else{
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = calc_parent(node[2 * k + 1] , node[2 * k + 2]);
    }
  }

  // 要求区間 [a, b) 中の要素の最小値を答える k := 自分がいるノードのインデックス 対象区間は [l, r) にあたる
  ll get(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
  {
    // 最初に呼び出されたときの対象区間は [0, n)
    if (r < 0)
      r = n;
    // 要求区間と対象区間が交わらない -> 適当に返す
    if (r <= a || b <= l)
      return unit;
    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    // 関数が呼び出されたら評価！
    eval(k, l, r);
    if (a <= l && r <= b)
      return node[k];
    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
    return calc_parent(vl, vr);
  }
};

int main()
{
ll n , q ;
cin >> n >> q ;

vector<ll> t(n,(1LL<<31)-1);
LazySegTree s(t);
vector<ll> ans;
rep(i,q){
  ll a  ;
  cin >> a  ;
  if(!a){
    ll b , c , d ;
    cin >> b >> c >> d ;
    s.update(b, c+1, d);
  }
  else {
    ll b ,c;
    cin >> b >>c;
    ans.push_back(s.get(b, c+1));
  }
}

rep(i,ans.size())cout<<ans[i]<<"\n";

return 0;
}
