#include <bits/stdc++.h>
using namespace std;

const int maxm=100000;

int n,m;
int father[maxm+1];
long long ans;

typedef struct
{
	int u,v,w;
}EDGE;

EDGE edges[maxm+1];

int find(int x)
{
	if(x!=father[x]){
		father[x]=find(father[x]);
	}
	return father[x];
}

bool cmp(const EDGE &a, const EDGE &b)
{
	return a.w<b.w; 
}

int unionn(int a, int b)
{
	int fa=find(a);
	int fb=find(b);
	father[fa]=fb;
}

int minitree()
{
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	
	sort(edges,edges+m,cmp);
	int count=0;
	
	for(int i=0;i<m;i++)
	{
		if(find(edges[i].u)!=find(edges[i].v)){
			//cout<<"49:"<<edges[i].u<<' '<<edges[i].v<<endl;
			ans+=(long long)edges[i].w;
			unionn(edges[i].u,edges[i].v);
			count++;
		}
		
		if(count==n-1){
			break;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	
	minitree();
}

/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
3 4 5
2 6 3
3 6 6
3 7 4
4 7 2
6 7 6
*/


