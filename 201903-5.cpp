#include <bits/stdc++.h>
using namespace std;

const int maxn=10002;
const int maxm=10002;
const int maxk=102;
const int INF=0x3f3f3f3f;

int M[maxn]={0},mymap[maxn]={0};
int n,m,k;

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

bool cmp(int a,int b)
{
	return a<b;
}

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
		
		q.push(HeapNode(d[s],s));
		
		while(!q.empty()){
			HeapNode x=q.top();
			q.pop();
			
			int u=x.u;
			if(done[u]) continue;
			done[u]=1;
			
			for(int i=0;i<G[u].size();i++){
				
				Edge &e=edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					q.push(HeapNode(d[e.to],e.to));
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			if(M[i]==0)	d[i]=INF;
		}
		
		sort(d,d+n,cmp);
		
		int res=0;
		for(int i=1;i<=k;i++){
			if(d[i]<INF) res+=d[i]; 
		}
		cout<<res<<endl;
	}
}DJ;


int findx(int x)
{
	for(int i=1;i<=n;i++){
		if(mymap[i]==x) return i;
	}
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>M[i];
	}
	
	DJ.setn(n);
	int st,en,we,countc;
//	map< pair<int,int>,int > mymap;
	
	while(m--)
	{
	//	pair<int,int> mypair;
		cin>>st>>en>>we;
	//	mypair=make_pair(st,en);|| mymap.find(mypair)!=mymap.end() 
		if(st==en ){
			continue;
		}
		DJ.addedge(st,en,we);
		DJ.addedge(en,st,we);
	//	mymap.insert(map<pair<int,int>,int>::value_type(mypair,1));
	//	mypair=make_pair(en,st);
	//	mymap.insert(map<pair<int,int>,int>::value_type(mypair,1));
	}
	
	for(int i=1;i<=n;i++)
	{
		DJ.dijkstra(i);
		
/*		for(int x=1;x<=n;x++){
			//cout<<x<<' '<<DJ.d[x]<<';';
			mymap[x]=DJ.d[x];
		}
		//cout<<endl;

		sort(DJ.d,DJ.d+n,cmp);
		
		for(int j=1;j<=n;j++)
		{
			int tmp=findx(DJ.d[j]);//cout<<tmp<<' ';
			if(M[tmp]==0||DJ.d[j]>INF){
				if(countc==k||j==n) {
					cout<<mysum<<endl;break;
				}
				continue;
			}
			
			if(M[tmp]==1&&DJ.d[j]<=INF){
				mysum+=DJ.d[j];
				countc++;
			}
			
			if(countc==k||j==n) {
				cout<<mysum<<endl;break;
			}
		}
*/	}
	
	return 0;
} 

/*
 		for(int x=1;x<=n;x++){
			mymap[x]=DJ.d[x];
			cout<<DJ.d[x]<<' ';
		}
		cout<<endl;
*/
