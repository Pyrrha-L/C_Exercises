#include <bits/stdc++.h>
using namespace std;

const int N=1000;

bool visited[N+1][N+1];
int mymap[N+1][N+1];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int store[N*N+1][2];

int n,m,k,d;
long long ans;

struct point
{
	int x,y;
	int step;
};

long long bfs()
{
	queue<point> bfsq[m];
	ans=0;
	
	point start[m];
	for(int i=0;i<m;i++){
		start[i].x=store[i][0];start[i].y=store[i][1];start[i].step=0;
		visited[start[i].x][start[i].y]=true;
		bfsq[i].push(start[i]);
	}
	
	int qcount=0;
	point tmp1,tmp2;
	while(1){
		
		for(int i=0;i<m;i++)//每个队列走一步 
		{	
			if(!bfsq[i].empty()){
				tmp1=bfsq[i].front();
				//cout<<tmp1.x<<' '<<tmp1.y<<' '<<tmp1.step<<endl;
				bfsq[i].pop();
			}
			else{
				continue;
			}
			
			for(int j=0;j<4;j++){
				tmp2.x=tmp1.x+dir[j][0];tmp2.y=tmp1.y+dir[j][1];
				
				if(visited[tmp2.x][tmp2.y]==true) continue;
				if(tmp2.x<=0||tmp2.x>n||tmp2.y<=0||tmp2.y>n) continue;
			//	if(mymap[tmp2.x][tmp2.y]==-1) continue;
				
				tmp2.step=tmp1.step+1;
				visited[tmp2.x][tmp2.y]=true;
				
				if(mymap[tmp2.x][tmp2.y]>0){
					ans+=(long long)mymap[tmp2.x][tmp2.y]*tmp2.step;
					//cout<<tmp2.x<<' '<<tmp2.y<<' '<<tmp2.step;
					qcount++;
					
					if(qcount==k){
						return ans;
					}
				}
				
				bfsq[i].push(tmp2);
			}
		}
	}
}

int main()
{
	for( int i=0;i<N+1;i++ )
	{
		for(int j=0;j<N+1;j++ )
		{
			mymap[i][j]=0;
		}
	}
	memset(visited,false,sizeof(visited));
	cin>>n>>m>>k>>d;
	
	for(int i=0;i<m;i++)
	{
		cin>>store[i][0]>>store[i][1];
	}
	
	int tmpx,tmpy,tmpz;
	for(int i=0;i<k;i++){
		cin>>tmpx>>tmpy>>tmpz;
		mymap[tmpx][tmpy]+=tmpz;
	}
	
	for(int i=0;i<d;i++){
		cin>>tmpx>>tmpy;
		//mymap[tmpx][tmpy]=-1;
		visited[tmpx][tmpy]=1;
	}
	
	bfs();
	
	cout<<ans;
}
