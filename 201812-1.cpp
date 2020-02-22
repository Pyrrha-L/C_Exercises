#include<iostream>
using namespace std;

int main()
{
	int r,y,g,N,k,tmpt,T;
	
	cin>>r>>y>>g;
	cin>>N;
	T=0;
	for(int i=0;i<N;i++){
		cin>>k>>tmpt;
		if(k==0||k==1){
			T+=tmpt;
		}
		else if(k==2){
			T+=tmpt+r;
		}
		else if(k==3){
			
		}
	}
	cout<<T<<endl;
 } 
