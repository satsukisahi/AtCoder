#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
    ll q;
    cin >> q;
    multiset<ll> slow;
    multiset<ll> shigh;
    ll cons = 0;
    ll fx = 0;
    ll med = INF;
    vector<ll> v;
    vector<ll> v1;
    ll le;
    rep(i, q)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll b, c;
            cin >> b >> c;
            cons += c;
            if (med < b){
                shigh.insert(b);
            }
            else{
                slow.insert(b);
            }

            if (shigh.size() > slow.size())
            {
                auto itr = shigh.begin();
                slow.insert(*itr);
                shigh.erase(shigh.begin());
            }

            else if (shigh.size() + 1 < slow.size())
            {
                auto itr = slow.end();
                itr--;
                shigh.insert(*itr);
                slow.erase(itr);
            }

            auto itrr = slow.end();
            itrr--;
            if(i!=0&&shigh.size() == slow.size())fx+=abs(med-b);
            else if(i!=0&&shigh.size() != slow.size()&&med>b)fx+=abs(med-b);
            else if(i!=0&&shigh.size() != slow.size()&&le<b)fx+=abs(le-b);
            med = *itrr;
            le=*shigh.begin();

        }
        else
        {
            v.push_back(med);
            v1.push_back(fx + cons);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " "<<v1[i]<< endl;;
    }
    return 0;
}