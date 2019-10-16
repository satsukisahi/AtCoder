#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

template< int char_size >
struct TrieNode {
  int nxt[char_size];

  int exist;
  vector< int > accept;

  TrieNode() : exist(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

template< int char_size, int margin >
struct Trie {
  using Node = TrieNode< char_size >;

  vector< Node > nodes;
  int root;

  Trie() : root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    nodes[node].accept.push_back(id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const string &str, int str_index, int node_index, int id) {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id) {
    add(str, 0, 0, id);
  }

  void add(const string &str) {
    add(str, nodes[0].exist);
  }

  void query(const string &str, const function< void(int) > &f, int str_index, int node_index) {
    for(auto &idx : nodes[node_index].accept) f(idx);
    if(str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int count() const {
    return (nodes[0].exist);
  }

  int size() const {
    return ((int) nodes.size());
  }


//ARC087-E用に書いたDFS
  vector<ll> ans;
  void solve(){
    dfs(root,0);
  }
  void dfs(int p,int dep){
    if(nodes[p].nxt[0]!=-1 && nodes[p].nxt[1]!=-1){
      dfs(nodes[p].nxt[0],dep+1);
      dfs(nodes[p].nxt[1],dep+1);
    }
    if(nodes[p].nxt[0]!=-1 && nodes[p].nxt[1]==-1){
      ans.push_back(dep);
      dfs(nodes[p].nxt[0],dep+1);
    }
    if(nodes[p].nxt[0]==-1 && nodes[p].nxt[1]!=-1){
      ans.push_back(dep);
      dfs(nodes[p].nxt[1],dep+1);
    }
  }
};

int main()
{
//文字種と辞書順最初の文字
Trie< 3, 'a' > trie;
//追加
trie.add("aa");
trie.add("aab");
trie.add("abc");
trie.add("aba");
/* 
null  a a b
        b a
          c
*/
//ノード数 null含む
cout << trie.size() << endl;
//存在する文字列の個数
cout << trie.count() << endl;
//文字列Sのプレフィックスに一致する文字列を検索する。一致した文字列ごとに関数が呼び出される。
auto c = [](int d){cout << d << endl;};
trie.query("aaba",c);

return 0;
}