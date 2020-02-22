#include <bits/stdc++.h>
using namespace std;

int mymap[10];

int space()
{
	int spa=0;
	for(int i=0;i<9;i++)
	{
		if(mymap[i]==0) spa++;
	}
	return spa;
}

int judge()
{
	int win=0;
	for(int i=0;i<9;i+=3){
		if(mymap[i]==mymap[i+1]&&mymap[i+1]==mymap[i+2]&&mymap[i]!=0){
			win=mymap[i];
			if(win==1) return space()+1;
			else return -(space()+1);
		}
	}
	
	for(int i=0;i<3;i++){
		if(mymap[i]==mymap[i+3]&&mymap[i+3]==mymap[i+6]&&mymap[i]!=0){
			win=mymap[i];
			if(win==1) return space()+1;
			else return -(space()+1);
		}
	}
	
	if(mymap[0]==mymap[4]&&mymap[4]==mymap[8]&&mymap[0]!=0){
		win=mymap[0];
		if(win==1) return space()+1;
		else return -(space()+1);
	}
	
	if(mymap[2]==mymap[4]&&mymap[4]==mymap[6]&&mymap[2]!=0){
		win=mymap[2];
		if(win==1) return space()+1;
		else return -(space()+1);
	}
	
	if(space()==0) return 0;
	if(win==0) return 100;
}

int dfs(int k)
{
	int val=judge();
	if(val!=100){
		return val;
	}
	
	int ans=0,mmax=-100,mmin=100;
	for(int i=0;i<9;i++)
	{
		if(mymap[i]==0){
			mymap[i]=k+1;
			if(k==0){
				mmax=max(mmax,dfs(1-k));
			}
			else{
				mmin=min(mmin,dfs(1-k));
			}
			mymap[i]=0;
		}
	}
	
	if(k==0) return mmax;
	else return mmin;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		for(int i=0;i<9;i++) cin>>mymap[i];
		cout<<dfs(0)<<endl;
	}
	return 0;
} 


/*
#include <bits/stdc++.h>
using namespace std;

const int msize=3; 

int mymap[3][3];

int Win(int flag)
{
	for(int i=0;i<3;i++)
	{
		if(mymap[i][0]==flag&&mymap[i][1]==flag&&mymap[i][2]==flag){
			return 0;
		}
	}
		
	for(int i=0;i<3;i++)
	{
		if(mymap[0][i]==flag&&mymap[1][i]==flag&&mymap[2][i]==flag){
			return 0;
		}
	}
		
	if(mymap[0][0]==flag&&mymap[1][1]==flag&&mymap[2][2]==flag){
		return 0;
	}
	if(mymap[0][2]==flag&&mymap[1][1]==flag&&mymap[2][0]==flag){
		return 0;
	}
	
	return 1;
}

int Count(int flag)
{
	int ret=0;
	for( int i=0;i<3;i++ )
	{
		for( int j=0;j<3;j++)
		{
			if(mymap[i][j]==0){
				ret++;
			}
		}
	}
	return ret;
}

int FindBest(int flag)
{
	int countt=0;
	int tmpord[2]; 
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(mymap[i][j]==flag){
				countt++;
			}
			else if(mymap[i][j]!=0){
				countt--;
			}
		}
		if(countt==2){
			return 0;
		}
	}
	
	countt=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(mymap[j][i]==flag){
				countt++;
			}else if(mymap[j][i]!=0){
				countt--;
			}
		}
		if(countt==2){
			return 0;
		}
	}
	
	countt=0;
	for(int j=0;j<3;j++)
	{
		if(mymap[j][j]==flag){
			countt++;
		}
		else if(mymap[j][j]!=0){
			countt--;
		}
	}
	if(countt==2){
		return 0;
	}
	
	countt=0;
	for(int j=0;j<3;j++)
	{
		if(mymap[2-j][j]==flag){
			countt++;
		}
		else if(mymap[2-j][j]!=0){
			countt--;
		}
	}
	if(countt==2){
		return 0;
	}

	return 1;
}

int Eval()
{
	if(!Win(1)){ //Alice
		return Count(1)+1;
	}
	else if(!Win(2)){
		return -Count(2)-1;
	}
	
	if(!FindBest(1)){ //Alice
		return Count(1);
	}
//	else if(!FindBest(2)){
//		return Count(2)+1;
//	}
	else{
		return 0;
	}
}

int dfs(int ab)
{
	if(Count(1)==0){
		return 0;
	}
	
	int Max=-10,Min=10;
	
	for( int i=0;i<3;i++ )
	{
		for( int j=0;j<3;j++ )
		{
			if(mymap[i][j]==0)
			{
				mymap[i][j]=ab+1;
				int w=Win(ab+1);
				if(w==0){
					//mymap[i][j]=0;
					if(ab==1){
						return min(Min,-Count(2)-1);
					}
					else{
						return max(Max,Count(1)+1);
					}
				}
				if(ab==0){
					Max=max(Max,dfs(1));
				}
				else{
					Min=min(Min,dfs(0));
				}
				mymap[i][j]=0; 
			}
		}
	}
}

int main()
{
	int T;
	
	cin>>T;
	
	for( int i=0;i<T;i++ )
	{
		
		for( int j=0;j<3;j++ )
		{
			for( int k=0;k<3;k++ )
			{
				mymap[j][k]=0;
			}
		}
		
		for( int j=0;j<3;j++ )
		{
			for( int k=0;k<3;k++ )
			{
				cin>>mymap[j][k];
			}
		}
		
		if(!Win(1)){ //Alice
			cout<<Count(1)+1<<endl;
		}
		else if(!Win(2)){
			cout<<-Count(2)-1<<endl;
		}
		else if(Count(1)==9){
			cout<<'0'<<endl;
		}
		else{
			cout<<dfs(0)<<endl;
		}
	}
	
	return 0;
}

*/
