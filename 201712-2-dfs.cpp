#include <bits/stdc++.h>
using namespace std;

const long long INF=10000000;

struct{
	int type,from,to,next;
	long long weight;
}edges[10002];

int n,m,vis[502],cur=0,head[502]; 
long long fin=INF;

int addedges(int type,int from,int to,long long weight)
{
	edges[cur].type=type;edges[cur].from=from;
	edges[cur].to=to;
	
	if(type==0) edges[cur].weight=weight;
	else edges[cur].weight=weight;
	
	edges[cur].next=head[from];
	head[from]=cur;cur++;
}

long long solve(int i,long long sum,long long tmpd)
{
	if(i==n){
		if(tmpd==0 ){
			fin=(sum<fin)?sum:fin;
			return sum;
		}
		else{
			fin=(sum+tmpd*tmpd<fin)?sum+tmpd*tmpd:fin;
			return sum+tmpd*tmpd;
		}
	}
	
	long long ret=INF;
	
	for(int x=head[i];x>-1;x=edges[x].next)
	{
		int k=edges[x].to;
		if(vis[k]==1) continue;
//		cout<<i<<' '<<k<<' '<<sum<<' '<<edges[x].type<<endl;
		vis[k]=1;
		
		if(tmpd>0)
		{
			if(edges[x].type==1){
				ret=solve(k,sum,tmpd+edges[x].weight);
			}
			else{
				ret=solve(k,sum+tmpd*tmpd+edges[x].weight,0);
			}
		}
		else{
			
			if(edges[x].type==0) {
				ret=solve(k,sum+edges[x].weight,0);
			}
			else{
				ret=solve(k,sum,edges[x].weight);
			}
		}
		
		
		vis[k]=0;
	}
	
//	if(i==1&&ret<fin) fin=ret;
}

int main()
{
	memset(vis,0,sizeof(vis));
	
	int ty,f,to;
	long long w;
	cin>>n>>m;
	
	for(int i=0;i<502;i++){
		head[i]=-1;
	}
	
	for(int i=0;i<m;i++){
		cin>>ty>>f>>to;
		cin>>w;
		addedges(ty,f,to,w);
	}

	vis[1]=1;
	solve(1,0,0);	
//	dijkstra();
	
	cout<<fin<<endl;
	
	return 0;
}
