#include <bits/stdc++.h>
using namespace std;

const int N = 200;
long long r,k,n,m;

struct point
{
	long long x,y;
	int step,kcount;
};

point allpo[N+1];
bool visited[N+1];

int bfs(int begin,int end)
{
	memset(visited,false,sizeof(visited));
	
	point tmp,tmp2;
	queue<point> bfsq;
	int ck=0;
	
	tmp.step=0;
	tmp.kcount=0;
	tmp.x=allpo[begin].x;
	tmp.y=allpo[begin].y;
	
	bfsq.push(tmp);
	visited[begin]=true;
	
	while(!bfsq.empty())
	{
		tmp=bfsq.front();
		bfsq.pop();
		
		if(tmp.x==allpo[end].x&&tmp.y==allpo[end].y){
			return tmp.step-1;
		}
		
		if(tmp.kcount==k){
			ck=n;
		}
		else{
			ck=n+m;
		}
		
		for(int i=0;i<ck;i++)
		{
			if(visited[i]) continue;
			if((allpo[i].x-tmp.x)*(allpo[i].x-tmp.x)+
				(allpo[i].y-tmp.y)*(allpo[i].y-tmp.y)>r*r)
				continue;
			else{
				
				tmp2.x=allpo[i].x;
				tmp2.y=allpo[i].y;
				
				if( i>=n ){
					tmp2.kcount=tmp.kcount+1;
				}
				else{
					tmp2.kcount=tmp.kcount;
				}
				
				visited[i]=true;
				tmp2.step=tmp.step+1;
				bfsq.push(tmp2);
			}
		}
	}
	
}

int main()
{	
	cin>>n>>m;
	cin>>k>>r;
	
	for(int i=0;i<n+m;i++ )
	{
		cin>>allpo[i].x>>allpo[i].y;
	}
	
	cout<<bfs(0,1);
}
