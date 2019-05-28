#include <bits/stdc++.h>
using namespace std;


int main()
{
int n;
cin >> n;
long long a[3 * n];
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long A[n + 1] = {};

for(int i=0;i<3*n;i++)
{
    cin >> a[i];
}
for(int i=0;i<n;i++)
{
    pq.push(a[i]);
    A[0] += a[i];
}
for(int i=n;i<2*n;i++){
    pq.push(a[i]);
    A[i -n+ 1] = A[i-n] + a[ i] - pq.top();
    pq.pop();
}
priority_queue<long long, vector<long long>> pql;
long long b[n + 1] = {};
for(int i=0;i<n;i++)
{
    pql.push(a[2 * n + i]);
    b[0] += a[2 * n + i];
}
for(int i=0;i<n;i++)
{
    pql.push(a[2 * n - 1 - i]);
    b[i + 1] = b[i] + a[2 * n - 1 - i] - pql.top();
    pql.pop();
}
long long ans = -1e18;
for(int i=0;i<=n;i++){
        ans=max(A[i]-b[n-i],ans);
    }

cout << ans << endl;

}