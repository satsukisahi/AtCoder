#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
ll ans = 0;
ll num[25];
ll zeropos[25] = {}; //zeroのindex→何個目のzeroか

bool check1()
{
    bool ok = 1;
    rep(i, 25)
    {
        if (i % 5 == 1 || i % 5 == 2 || i % 5 == 3)
        {
            if (num[i] * num[i - 1] * num[i + 1] != 0)
            {
                if (num[i - 1] > num[i] && num[i] > num[i + 1])
                    ok = 0;
                if (num[i - 1] < num[i] && num[i] < num[i + 1])
                    ok = 0;
            }
        }
        if (4 < i && i < 20)
        {
            if (num[i] * num[i - 5] * num[i + 5] != 0)
            {
                if (num[i - 5] > num[i] && num[i] > num[i + 5])
                    ok = 0;
                if (num[i - 5] < num[i] && num[i] < num[i + 5])
                    ok = 0;
            }
        }
    }
    return ok;
}

bool check(ll pu, ll ad, ll ii)
{
    ll cnt = 0;
    if (ad % 5 == 1 || ad % 5 == 2 || ad % 5 == 3)
    {
        if (num[ad + 1] != 0 && num[ad + 1] < pu)
            cnt++;
        if (num[ad + 1] == 0 && ((ii >> zeropos[ad + 1]) & 1LL))
            cnt++;
        if (num[ad - 1] != 0 && num[ad - 1] < pu)
            cnt++;
        if (num[ad - 1] == 0 && ((ii >> zeropos[ad - 1]) & 1LL))
            cnt++;
    }
    if (cnt == 1)
        return false;
    cnt = 0;
    if (4 < ad && ad < 20)
    {
        if (num[ad + 5] != 0 && num[ad + 5] < pu)
            cnt++;
        if (num[ad + 5] == 0 && ((ii >> zeropos[ad + 5]) & 1LL))
            cnt++;
        if (num[ad - 5] != 0 && num[ad - 5] < pu)
            cnt++;
        if (num[ad - 5] == 0 && ((ii >> zeropos[ad - 5]) & 1LL))
            cnt++;
    }
    if (cnt == 1)
        return false;
    return true;
}

int main()
{
    vector<ll> defindex(26); //すでに入る数のindex
    vector<ll> ketatoindex;  //0の桁数をnumのindex
    vector<ll> insertnum;    //入れるべき数字　昇順
    set<ll> s;
    ll ze = 0;
    rep(i, 25)
    {
        cin >> num[i];
        s.insert(num[i]);
        if (num[i] == 0)
        {
            zeropos[i] = ze;
            ze++;
            ketatoindex.push_back(i);
        }
        else
        {
            defindex[num[i]] = i;
        }
    }
    insertnum.push_back(0);
    rep(i, 25)
    {
        if (s.find(i + 1) == s.end())
            insertnum.push_back(i + 1);
    }
    if (!check1())
    {
        cout << 0 << endl;
        return 0;
    }
    if (insertnum.size() - 1 == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    ll dp[1LL << (insertnum.size() - 1)] = {};
    dp[0] = 1;

    rep(i, (1LL << (insertnum.size() - 1)) - 1)
    {

        bool ok = 0;
        for (ll j = insertnum[__builtin_popcountll(i)] + 1; j < insertnum[__builtin_popcountll(i) + 1]; j++)
        {
            if (check(j, defindex[j], i) == false)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        ll putnum = insertnum[__builtin_popcountll(i) + 1];
        rep(j, insertnum.size() - 1)
        {
            if (((i >> j) & 1LL) == 0 && check(putnum, ketatoindex[j], i))
            {
                dp[i ^ (1LL << j)] += dp[i];
                dp[i ^ (1LL << j)] %= mo;
            }
        }
    }

    cout << dp[(1LL << (insertnum.size() - 1)) - 1] << endl;
    return 0;
}
