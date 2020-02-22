#include <bits/stdc++.h>
using namespace std;

const int maxn=302;
int n,flag=0,a[maxn]={0},x[maxn]={0},xm[maxn]={0};

int update()
{
	int f=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]<1) return 0;	
	}
	
	int f2=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==xm[i]) continue;
		else {
			f2=i;break;
		}
	}
	
	if(x[f2]>xm[f2]) return 0;
	if(x[f2]<xm[f2]) f=1;
	
	if(f){
		for(int i=1;i<=n;i++) xm[i]=x[i];
	}
		
}

int dfs()
{
	int f,tmp;
	for(int i=1;i<=2*a[1]-1;i++){
		f=0;
		x[1]=i;x[2]=2*a[1]-x[1];
		
		tmp=1;
		while(x[2]<1&&tmp<2){
			x[2]=2*a[1]-x[1]+tmp;
			tmp++;
		}
		
		for(int j=3;j<n;j++){
			x[j]=3*a[j-1]-x[j-2]-x[j-1];
			tmp=1;
			while(x[j]<1&&tmp<3){
				x[j]=3*a[j-1]+tmp-x[j-2]-x[j-1];
				tmp++;
			}
		}
		
		x[n]=2*a[n]-x[n-1];
		tmp=1;
		while(x[n]<1&&tmp<2){
			x[n]=2*a[n]-x[n-1]+tmp;
			tmp++;
		}
		
		for(int i=1;i<=n;i++) {
			if(x[i]<1) {
				f=1;break;
			}
		}
		//cout<<x[i]<<' ';
		//cout<<endl;
		
		if(flag==0&&f==0){
			flag=1;
			for(int i=1;i<=n;i++) xm[i]=x[i];
		}
		else if(flag==1&&f==0){
			update();
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	dfs();
	
	for(int i=1;i<=n;i++) cout<<xm[i]<<' ';
	return 0;
}

/*
const int maxn=306;

int n,a[maxn],vis[maxn],head[maxn],curs=0,inq[maxn],dist[306];

typedef struct
{
	int to,v,next;
}EDGE;

EDGE edges[2006];
queue<int> myq;

int addedge(int x, int y, int v)
{
	edges[curs].to=y;
	edges[curs].v=v;
	edges[curs].next=head[x];
	head[x]=curs;
	curs++;
}

void spfa()
{
	
	for(int i=0;i<=n;i++)
	{
		myq.push(i);
		vis[i]=1;dist[i]=0;inq[i]=1;
	}
	
	while(!myq.empty())
	{
		int u=myq.front();
		cout<<"37:"<<u<<endl;
		myq.pop();
		inq[u]++;
		vis[u]=0;
		
		for(int i=head[u];i!=-1;i=edges[i].next)
		{
			cout<<"44:"<<i<<endl;
			int nu=edges[i].to;
			if(dist[nu]<dist[u]+edges[i].v)
			{
				dist[nu]=dist[u]+edges[i].v;
				if(vis[nu]==0)
				{
					vis[nu]=1;
					myq.push(nu);
				}
			}
		}
	}
	
	return;
}

int main()
{
	memset(head,-1,sizeof(head));
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n-2;i++){
		addedge(i+3,i,-(3*a[i+2]+2));addedge(i,i+3,(3*a[i+2]));
	}
	addedge(2,0,-(2*a[1]+1));addedge(0,2,2*a[1]);
	addedge(n,n-2,-(2*a[n]+1));addedge(n-2,n,2*a[n]);
	
	for(int i=1;i<=n;i++)
	{
		addedge(i-1,i,1);
	}
	
	for(int i=0;i<curs;i++)
     {
     	cout<<edges[i].v<<' '<<edges[i].to<<' '<<edges[i].next<<endl;
	 }
	
	spfa();
	
	a[1]=dist[1];
	for(int i=2;i<=n;i++)
	{
		a[i]=dist[i]-dist[i-1];
	}
	
	cout<<a[1];
	for(int i=2;i<=n;i++){
		cout<<' '<<a[i];
	}
	return 0;
}
*/ 
