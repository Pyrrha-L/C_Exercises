#include <bits/stdc++.h>
using namespace std;

int cal(int i,int j,int x)
{
	return i*4+j*7+x/10;
}

int main()
{
	int N,tmp,mmax=0;
	cin>>N;
	
	for(int i=0;i<=(N/30);i++){ 
		for(int j=0;j<=(N-i*30)/50;j++)
		{
			if((tmp=cal(i,j,N-i*30-j*50))>mmax) mmax=tmp;
		}
	}
	cout<<mmax<<endl;
	return 0;
}
