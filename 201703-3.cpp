#include <bits/stdc++.h>
using namespace std;

const int INF=1000002;
int n,m;
int mymap[100002][100002];
bool vis[100002];

int dfs(int s,int val)
{
	for(int i=1;i<=n;i++)
	{
		if(mymap[s][i]<INF&&vis[i]==false)
		{
			vis[i]=true;
			if(i==n){
				return (val<mymap[s][i])?mymap[s][i]:val;
			}
			
			if(val<mymap[s][i]) dfs(i,mymap[s][i]);
			else dfs(i,val);
			
			vis[i]=false;
		}
	}
} 

int main()
{
	for(int i=0;i<100002;i++){
		vis[i]=false;
		for(int j=0;j<100002;j++)
			mymap[i][j]=INF;
	}
	
	cin>>n>>m;
	int st,en,we;
	while(m--)
	{
		cin>>st>>en>>we;
		mymap[st][en]=we;
	}
	
	vis[1]=true;
	int ret=dfs(1,0);
	cout<<ret<<endl;
}
