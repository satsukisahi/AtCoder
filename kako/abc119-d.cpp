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


int main()
{

//整数値の入力
int a,b,q;
cin >> a>>b>>q;
//行列の入力
ll jin[a+2];
ll tera[b+2];
ll start[q]={};

jin[0]=-1000000000000;
for (int i = 1; i < a+1; ++i) {
    cin >> jin[i];
}
jin[a+1]=1000000000000;
tera[0]=-1000000000000;
for (int i = 1; i < b+1; ++i) {
    cin >> tera[i];
}
tera[b+1]=1000000000000;

for (int i = 0; i < q; ++i) {
    cin >> start[i];
}

for (int i = 0; i < q; ++i) {
  ll ans=0;
  int nextjin=lower_bound(jin, jin+a+2,start[i])-jin;
  int nexttera=lower_bound(tera, tera+b+2,start[i])-tera;


  ans=min({
    
    abs(start[i]-jin[nextjin])+abs(tera[nexttera]-jin[nextjin]),
    abs(start[i]-tera[nexttera])+abs(tera[nexttera]-jin[nextjin]),
    abs(start[i]-jin[nextjin-1])+abs(tera[nexttera]-jin[nextjin-1]),
    abs(start[i]-tera[nexttera-1])+abs(tera[nexttera-1]-jin[nextjin]),
    abs(start[i]-jin[nextjin])+abs(tera[nexttera-1]-jin[nextjin]),
    abs(start[i]-tera[nexttera])+abs(tera[nexttera]-jin[nextjin-1]),
    abs(start[i]-jin[nextjin-1])+abs(tera[nexttera-1]-jin[nextjin-1]),
    abs(start[i]-tera[nexttera-1])+abs(tera[nexttera-1]-jin[nextjin-1]),
    });

  cout << ans << endl; 
}




return 0;
}

