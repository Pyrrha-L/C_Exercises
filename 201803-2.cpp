#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int dire;
	int pos;
}BALL;

int main()
{
	BALL balls[102];
	int Lrec[1001]={0};
	int n,L,t;
	cin>>n>>L>>t;
	
	for( int i=1;i<=n;i++ )
	{
		cin>>balls[i].pos;
		balls[i].dire=1;
	}
	
	for( int i=1;i<=t;i++ )
	{
		for( int j=1;j<=n;j++ )
		{
			int tmppos=balls[j].pos+balls[j].dire;
			if(tmppos==L||tmppos==0){
				balls[j].dire*=-1; 
			}
			else if(Lrec[tmppos]!=0)
			{
				balls[j].dire*=-1;
				balls[Lrec[tmppos]].dire*=-1;
			}
			Lrec[tmppos]=j;
			Lrec[balls[j].pos]=0;
			balls[j].pos=tmppos;
			
			//cout<<balls[j].pos<<' ';
		}
		//cout<<"----"<<i<<endl;
		
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<balls[i].pos<<' ';
	}
	
	return 0;
} 
