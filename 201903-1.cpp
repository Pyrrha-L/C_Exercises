/*
#include <iostream>
#include <iomanip>
#include <cmath>
*/
#include <stdio.h> 
//using namespace std;

int main()
{
	int N;
	//cin>>N;
	scanf("%d",&N);
	long max;
	long min;
	double middle;
	long tmp;
	long tmp2;
	long tmp3;
	int flag=0;
	int i;
	
	for( i=0;i<N;i++ )
	{
		scanf("%ld",&tmp);
		if(i==0){
			max = tmp;
		}
		if(i==N-1){
			min = tmp;
		}
		
		if( N%2==1 && i==N/2 ){
			tmp3 = tmp;
			flag = 1;
		}
		
		if( N%2==0 && i==N/2-1 ){
			tmp2 = tmp;
		}
		
		if( N%2==0 && i==N/2 ){
			tmp3 = tmp;
		}
	}
	
	long tmp4;
	if( max<min ){
		tmp4 = max;
		max = min;
		min = tmp4;
	} 
	
	
	if( flag ==1 ){
		printf("%ld %ld %ld\n",max,tmp3,min);
		return 0;
	}
	else if( (tmp2+tmp3)%2==0 ){
		printf("%ld %ld %ld\n",max,(tmp2+tmp3)/2,min);
		return 0;
	}
	else{
		printf("%ld %.1lf %ld\n",max,(tmp2+tmp3)/2.0,min);
		return 0;
	}
	
/*	cout<<max<<' ';
	cout<<setprecision(1)<<middle<<' ';
	cout<<min<<endl;
*/	
	return 0;
 } 
