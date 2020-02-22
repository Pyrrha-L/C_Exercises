#include <bits/stdc++.h>
using namespace std;

int n,ans;
int H[2001][2];
int W[2001][2];

int GetInsect(int i,int j)
{
	if(H[i][0]>=W[j][1] || H[i][1]<=W[j][0])
	{
		return 0;
	}
	
	return min(H[i][1],W[j][1])-max(H[i][0],W[j][0]);
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>H[i][0]>>H[i][1];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>W[i][0]>>W[i][1];
	}
	
	ans=0;
	for(int i=0;i<n;i++)
	{
		cout<<i<<endl; 
		for(int j=0;j<n;j++)
		{
			if(GetInsect(i,j)){
				cout<<i<<' '<<j<<endl;
				ans+=GetInsect(i,j);
				//break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

/*
4
1 3
6 8
9 13
14 15
5 7
8 9
10 11
13 14
*/
