#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>G[4<<17];
int N,A[2<<17],B[2<<17];
bool vis[4<<17];
pair<int,int>dfs(int u,int p)
{
	pair<int,int>ret=make_pair(1,G[u].size());
	vis[u]=true;
	for(int v:G[u])
	{
		if(v==p||vis[v])continue;
		pair<int,int>p=dfs(v,u);
		ret.first+=p.first;
		ret.second+=p.second;
	}
	return ret;
}
main()
{
	cin>>N;
	vector<int>X;
	for(int i=0;i<N;i++)
	{
		cin>>A[i]>>B[i];
		X.push_back(A[i]);
		X.push_back(B[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	for(int i=0;i<N;i++)
	{
		int a,b;
		a=lower_bound(X.begin(),X.end(),A[i])-X.begin();
		b=lower_bound(X.begin(),X.end(),B[i])-X.begin();
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans=0;
	for(int i=0;i<X.size();i++)
	{
		if(!vis[i])
		{
			pair<int,int>p=dfs(i,-1);
			ans+=min(p.first,p.second/2);
		}
	}
	cout<<ans<<endl;
}
