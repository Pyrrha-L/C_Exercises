#include <bits/stdc++.h>
using namespace std;

const long long INF=10000000;
const int maxm=100002;
const int maxn=502;
int n,m;

struct Edge{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){}
};

struct HeapNode{
	int d,u;
	HeapNode(){	}
	HeapNode(int d,int u):d(d),u(u){ }
	bool operator < (const HeapNode &rhs)const{ return d>rhs.d; };
};

struct Dijkstra{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	
	Dijkstra(){}
	
	void setn(int n){
		this->n=n;
		for(int i=1;i<=n;i++) G[i].clear();
		edges.clear();
	}
	
	void addedge(int ty,int from,int to,int dist){
		if(ty==0) edges.push_back(Edge(from,to,dist));
		else edges.push_back(Edge(from,to,dist*dist));
		m=edges.size();
		G[from].push_back(m-1);
	}
	
	void dijkstra(int s){
		memset(done,0,sizeof(done));
		priority_queue<HeapNode> q;
		
		for(int i=1;i<=n;i++){
			d[i]=INF;
		}
		d[s]=0;
		
		q.push(HeapNode(d[s],1));
		
		while(!q.empty()){
			HeapNode x=q.top();
			q.pop();
			
			int u=x.u;
			if(done[u]) continue;
			done[u]=1;
			
			for(int i=0;i<G[u].size();i++){
				
				Edge &e=edges[G[u][i]];
//				cout<<"61:"<<e.to<<' '<<u<<endl;
//				cout<<d[e.to]<<' '<<d[u]<<' '<<e.dist<<endl;
				if(d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					q.push(HeapNode(d[e.to],e.to));
				}
			}
		}
	}
}DJ;


int main()
{	
	int ty,f,to;
	long long w;
	cin>>n>>m;
	DJ.setn(n);
	
	for(int i=0;i<m;i++){
		cin>>ty>>f>>to;
		cin>>w;
		DJ.addedge(ty,f,to,w);
		DJ.addedge(ty,to,f,w);
	}
	
	DJ.dijkstra(1);
	cout<<DJ.d[n]<<endl;
	
	return 0;
}

/*
5 8
0 1 2 2
0 1 5 10
0 2 5 7
0 1 3 4
0 5 3 3
0 4 5 5
0 3 4 4
0 2 3 3

struct{
	int type,from,to,next;
	long long weight;
}edges[10002];

int n,m,vis[502],cur=0,head[502]; 
long long dist[502];
long long fin=INF;

int addedges(int type,int from,int to,long long weight)
{
	edges[cur].type=type;edges[cur].from=from;
	edges[cur].to=to;
	
	if(type==0) edges[cur].weight=weight;
	else edges[cur].weight=weight*weight;
	
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

int dijkstra()
{
	vis[1]=1;
	int countv=1;
	dist[1]=0;
	
	for(int i=head[1];i>-1;i=edges[i].next)
	{
		int t=edges[i].to;
		dist[t]=edges[i].weight;
		cout<<"85:"<<t<<endl;
	}
	
	while(countv!=n)
	{
		long long mmin=INF;
		int mmini=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0&&dist[i]<mmin){
				mmin=dist[i];
				mmini=i;
			}
		}
		
		cout<<"100:"<<mmini<<' '<<mmin<<endl;
		countv++;
		vis[mmini]=1;
		cout<<mmini<<endl;
		
		for(int i=1;i<=n;i++)
		{
			cout<<dist[i]<<' ';
		}
		cout<<endl;
		
		for(int i=head[mmini];i>-1;i=edges[i].next)
		{
			int k=edges[i].to;
			if(vis[k]==0) dist[k]=min(dist[k],dist[mmini]+edges[i].weight);
		}
	}
	
}
*/
