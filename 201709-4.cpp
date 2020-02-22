#include <bits/stdc++.h>
using namespace std;

const int maxn=1001;

bool mymap[maxn][maxn];
bool knowmap[maxn][maxn];
bool visited[maxn];
int mycount[maxn]={0};
int vexn[maxn]={0};

int N,M;

int DFS(int i, int s)
{
	for( int j=1;j<=N;j++ )
	{
		if( mymap[i][j]==true && visited[j]==false )
		{
			visited[j]=true;
			knowmap[j][s]=true;knowmap[s][j]=true;
			DFS(j,s);
		}
	}
}

int main()
{
	cin>>N>>M;
	
	memset(mymap,false,sizeof(mymap));
	
	int x,y;
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		mymap[x][y]=true;
	}
	
	for(int i=1;i<=N;i++)
	{
		memset(visited,false,sizeof(visited));
		visited[i]=true;
		DFS(i,i);
	}
	
	int allc;
	for(int i=1;i<=N;i++)
	{
		int countk=0;
		for(int j=1;j<=N;j++)
		{
			if(knowmap[i][j]==true) countk++;
		}
		if(countk==N-1) allc++;
	}
	
	cout<<allc<<endl;
	return 0;
	
}
