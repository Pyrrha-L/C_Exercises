#include<iostream>
using namespace std;

long long r,y,g,N,k,tmpt,T;

int tgreatT(long long k,long long tmpt)
{
	long long T0=T;
	if(k==0||k==1){
		T+=tmpt;
	}
	else if(k==2){
		T+=tmpt+r;
	}
	else if(k==3){
		
	}
}

int Tgreatt(long long k,long long tmpt)
{
	long long T0=T; 
	long long a=T%(r+y+g);
	if(k==1){
		if(a<tmpt){
			T+=tmpt-a;
		}
		else if(a<g+tmpt){
		}
		else if(a<y+g+tmpt){
			T+=r+g+y+tmpt-a;
		}
		else{
			T+=r+g+y-a+tmpt;
		}
	}
	else if(k==3){
		if(a<tmpt){
		}
		else if(a<y+tmpt){
			T+=r+y+tmpt-a;
		}
		else if(a<y+r+tmpt){
			T+=r+y+tmpt-a;
		}
		else{
			
		}
	}
	else if(k==2){
		if(a<tmpt){
			T+=r+tmpt-a;
		}
		else if(a<r+tmpt){
			T+=r+tmpt-a;
		}
		else if(a<g+r+tmpt){
		}
		else{
			T+=2*r+g+y+tmpt-a;
		}
	}
}

int main()
{	
	cin>>r>>y>>g;
	cin>>N;
	T=0;
	for(long long i=0;i<N;i++){
		cin>>k>>tmpt;
		if(tmpt>T||k==0){
			tgreatT(k,tmpt);
		}
		else{
			Tgreatt(k,tmpt);
		}
	}
	cout<<T<<endl;
 }
 
/*
30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3

30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3

30 3 30
8
0 60
1 14
0 12
2 2
0 9
0 2
3 15
0 9
*/
