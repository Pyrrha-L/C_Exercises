#include<iostream>
#include<algorithm>
using namespace std;
const int maxx=100010;
int n,m,root,tot,ans,father[maxx];
struct node
{
	int u;
	int v;
	int w;
}e[maxx];
int find(int x)//ตÝน้ 
{
	if(x!=father[x])
	father[x]=find(father[x]);
	return father[x];
}
void unionn(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
	father[fa]=fb;
}
bool cmp(const node &a,const node &b)
{
	return a.w<b.w;
}
int main()
{
	ans=-0x7f;
	cin>>n>>m>>root;
	for(int i=1;i<=m;i++)
	cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=n;i++)
	father[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			unionn(e[i].u,e[i].v);
			ans=max(ans,e[i].w);
			tot++;
		}
		if(tot==n-1)
		break; 
	}
	cout<<ans;
	return 0;
}

