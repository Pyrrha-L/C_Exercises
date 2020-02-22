#include <stdio.h>

int main()
{
	int arr[10000]={0};
	int n;
	int i;
	int tmp;
	
	scanf("%d",&n);
	
	for( i=0;i<n;i++ ){
		scanf("%d",&tmp);
		arr[tmp-1]++;
	}
	
	tmp = 0;
	for( i=0;i<10000;i++ ){
		if( arr[i] > arr[tmp] ){
			tmp = i;
		}
	}
	
	printf("%d",tmp+1);
	
	return 0;
 } 
