#include <bits/stdc++.h>
using namespace std;

const int INF=1000002;
const int maxn=100002;
int n,m,mymin;

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
	
	void addedge(int from,int to,int dist){
		edges.push_back(Edge(from,to,dist));
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
				if(d[e.to]>max(d[u],e.dist)){
					d[e.to]=max(d[u],e.dist);
					q.push(HeapNode(d[e.to],e.to));
				}
			}
		}
	}
}DJ;

int main()
{
	cin>>n>>m;
	DJ.setn(n);
	int st,en,we;
	while(m--)
	{
		cin>>st>>en>>we;
		DJ.addedge(st,en,we);
		DJ.addedge(en,st,we);
	}
	
	DJ.dijkstra(1);

	cout<<DJ.d[n]<<endl;
}

/*
int dfs(int s,int val)
{
	for(int i=1;i<=n;i++)
	{
		if(mymap[s][i]<INF&&vis[i]==false)
		{
			//cout<<s<<'-'<<i<<" val:"<<val<<' '; 
			vis[i]=true;
			if(i==n){
				vis[i]=false;
				int tmpmax=(val<mymap[s][i])?mymap[s][i]:val;
				if(tmpmax<mymin) mymin=tmpmax;
				return tmpmax;
			}
			
			if(val<mymap[s][i]) dfs(i,mymap[s][i]);
			else dfs(i,val);
			
			vis[i]=false;
		}
	}
} 

	
	mymin=INF;
	vis[1]=true;
	int ret=dfs(1,0);
	//cout<<endl;
*/
