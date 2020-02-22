#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int height[1000]={0};
	int i;
	
	int minheight = 10001;
	int maxheight = 0;
	
	scanf("%d",&n);
	for( i=0;i<n;i++ ){
		scanf("%d",&height[i]);
		minheight = (height[i]<minheight)?height[i]:minheight;
		maxheight = (height[i]>maxheight)?height[i]:maxheight;
	}
	
	int j,k;
	int maxarea = 0;
	int tmpwidth = 0;
	
	for ( i=minheight;i<=maxheight;i++ ){
		for ( j=0;j<n;j++ ){
			//printf("26:%d %d\n",i,height[j]);
			if( height[j]>= i ){
				for ( k=j;k<n;k++ ){
					if( height[k]>= i ){
						tmpwidth ++;
					}
					else
					{
						//printf("33:%d %d\n",i,tmpwidth);
						if( i*tmpwidth>maxarea ){
							maxarea = i*tmpwidth;
						}
						tmpwidth = 0;
						j=k;
						break;
					}
					
					if( k==n-1){
						maxarea = (i*tmpwidth>maxarea)?i*tmpwidth:maxarea;
						tmpwidth=0;
					}
					
				}
			}
		}
	}
	
	printf("%d\n",maxarea);
}
