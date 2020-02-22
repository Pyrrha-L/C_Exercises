#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL Q=1000000007;
int T,N,M,L,R,u,v,sum2=0,ro=0;
LL d;

struct node{
	LL a,fa,no;
}node[2001];

int route1[2001]={0};
LL sumarr[2001]={0};

int addw(int u,int v,int d)
{
	if(u==v){
		node[u].a+=d;
		return 0;
	}
	else{
		//for(int j=1;j<=N;j++) cout<<"75: "<<j<<' '<<node[j].fa<<endl;
		//cout<<u<<' '<<node[u].fa<<endl;
		node[u].a+=d;
		addw(node[u].fa,v,d);
	}
	
}

int getsum2()
{
	for(int i=1;i<=N;i++)
	{
		sum2+=sumarr[i];
	}
}

int findroute(int st, int x, int k, int L, int R, LL sum)
{
	if(k>=L&&k<=R){
		sumarr[st]+=sum;
		findroute(st,node[x].fa,k+1,L,R,sum+node[x].a);
		sum-=node[x].a;
	}
	else if(k<L){
		sum+=node[x].a;
		findroute(st,node[x].fa,k+1,L,R,sum);
		sum-=node[x].a;
	}
	else if(k>R||node[x].fa==x){
		return sum;
	}
}

int Cal(int L,int R)
{
	for(int i=1;i<=N;i++)
	{
		findroute(i,i,1,L,R,node[i].a);
	}
	getsum2();
	cout<<sum2%Q<<endl;
	sum2=0;
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M>>L>>R;
		for(int i=1;i<=N;i++) cin>>node[i].a;
		for(int i=2;i<=N;i++) cin>>node[i].fa;
		node[1].fa=1;
		
		for(int i=1;i<=M;i++){
			
			cin>>u>>v;cin>>d;
			memset(route1,0,sizeof(route1));
			
			if(u>v) addw(u,v,d);
			else addw(v,u,d);
			for(int i=1;i<=N;i++) cout<<node[i].a<<' ';
			cout<<endl;
			Cal(L,R);
		}
	}
	return 0;
}
