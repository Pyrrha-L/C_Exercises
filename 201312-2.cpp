#include <stdio.h>
#include <string.h>

int main()
{
	char input[15];
	char * right="Right";
	int trans[3]={0};
	char tail;
	
	gets(input);
	sscanf(input,"%d-%d-%d-%c",&trans[0],&trans[1],&trans[2],&tail);
	
	int n = 0;
	int m =1;
	int sum = 0;
	int tmp1;
	int tmp2;
	int tmp3;
	
	sum += trans[0]*m;
	m++;
	
	tmp1 = trans[1];
	tmp3 = trans[1];
	tmp2 = 100;
	
	for ( n=0;n<3;n++ ){
		tmp1=tmp3/tmp2;
		//printf("39:%d %d\n",tmp1,m);
		sum += tmp1*m;
		tmp3 = tmp3-tmp1*tmp2;
		tmp2/=10;
		m++;
	}

	tmp1 = trans[2];
	tmp3 = trans[2];
	tmp2 = 10000;
	
	for ( n=0;n<5;n++ ){
		tmp1=tmp3/tmp2;
		//printf("39:%d %d\n",tmp1,m);
		sum += tmp1*m;
		tmp3 = tmp3-tmp1*tmp2;
		tmp2/=10;
		m++;
	}

	
	sum %= 11;
	//printf("sum:%d\n",sum);
	
	if( sum==10 ){
		if( tail == 'X' ){
			printf("%s\n",right);
		}
		else{
			printf("%d-%d-%d-X\n",trans[0],trans[1],
			trans[2]);
		}
	}
	else{
		if( tail-'0'==sum ){
			printf("%s\n",right);
		}
		else{
			printf("%d-%d-%d-%d\n",trans[0],trans[1],
			trans[2],sum);
		}
	}
	
	return 0;
}
