#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int isnum(char c)
{
	if( c>='0'&&c<='9'){
		return 1;
	}
	return 0;
}

int cmppri(int a,int b){
	int prib,pria;
	
	if( b=='x'||b==47){
		prib=2;
	}
	else{
		prib=1;
	}
	
	if(a=='x'||a==47 ){
		pria=2;
	}
	else{
		pria=1;
	}
	
	if( prib<pria ){
		return 1;
	}
	else{
		return 0;
	}
}

int clearstack(int * stack,int n)
{
	int j;
	
	for( j=0;j<n;j++ ){
		*(stack+j)=0; 
	} 
	
	return 0;
}

int main()
{
	int N;
	cin>>N;
	char * line = (char *)malloc(sizeof(char)*10);
	int houzhui[10] = {0};
	int res[101]={0};
	int stack[8]={0};
	int i,j;
	int minusf = 0;
	
	for( i=0;i<N;i++ ){
		memset(line,'\0',10);
		houzhui[0]=0;
		cin>>line;
		
		int tmp;
		for( j=0;j<7;j++ ){	
			if( isnum(line[j]) ){
				houzhui[++houzhui[0]]=line[j]-'0';
				if( minusf ){
					houzhui[houzhui[0]]*=(-1);
					minusf = 0;
				}
				if (stack[stack[0]] == 'x'){	//需要x运算
					tmp = houzhui[houzhui[0]] * houzhui[houzhui[0]-1];
					houzhui[--houzhui[0]] = tmp;
					--stack[0];
				}
				else if(stack[stack[0]] == '/'){	//需要/运算
					tmp = houzhui[houzhui[0]-1] / houzhui[houzhui[0]];
					houzhui[--houzhui[0]] = tmp;
					--stack[0];
				}
			}
			else{
				if( line[j]==45 ){
					line[j]='+';
					minusf = 1;
				}
				stack[++stack[0]]=line[j];
			}
		}
		
		while(stack[0]){
			tmp = houzhui[houzhui[0]] + houzhui[houzhui[0]-1];
			houzhui[--houzhui[0]] = tmp;
			--stack[0];
		}
		
		if(houzhui[1]==24){
			res[i]=1;
		}
		else{
			res[i]=0;
		}
		
//		cout<<houzhui[1]<<endl;
		
		for( j=0;j<8;j++ ){
			*(stack+j)=0; 
		} 
	}
	
	for( i=0;i<N;i++ ){
		if(res[i]==1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}

/*
houzhui[0]=line[0];
			stack[++stack[0]]=line[1];
			houzhui[1]=line[2];
			
			if(cmppri(line[1],line[2])==0){
				stack[++stack[0]]=line[2];
			}
			else{
				houzhui[2]=line[2];
			}
*/
/* 
int Parser( char * line )
{
	char * line2 = (char *)malloc(sizeof(char)*INPUTLENGTH);
	strcpy(line2,line);
	
	int sig[4]={0};
	int num[4]={0};
	int opr[3]={0};
	
	int i;
	for( i=0;i<4;i++ ){
		num[0] = *(line+2*i)-'0';
	}
	
	int res;
	for( i=1;i<=5;i+=2 ){
		if( *(line+i)=='+' ){
			opr[i/2]=1;
		}
		else if( *(line+i)=='-' ){
			opr[i/2]=2;
		}
		else if( *(line+i)=='x' ){
			opr[i/2]=3;
		}else if( *(line+i)=='/' ){
			opr[i/2]=4;
		}
	}
	int tmp = 0;
	int max = 0;
	for( i=0;i<3;i++ ){
		if(opr[i]==3){
			tmp = num[i]*num[i+1];
			num[i] = tmp;
			num[i+1] = tmp;
			sig[i] = i+1;
			sig[i+1] = i+1;
			max = i+1;
		}
		if(opr[i]==4){
			tmp = num[i]/num[i+1];
			num[i] = tmp;
			num[i+1] = tmp;
			sig[i] ++;
			sig[i+1] = i+1;
			max = i+1;
		}
	}
	
	for( i=0;i<4;i++ )
	{
		if(sig[i]!=0){
			sig[i]=max;
		}
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	char * line = (char *)malloc(sizeof(char)*INPUTLENGTH);
	int i;
	
	for( i=0;i<N;i++ ){
		gets(line);
		Parser(line);
	}
	
	return 0;
}
*/
/* AC COX 
#include <iostream>
using namespace std;

int main(){
	int n, num[5], temp;//行数 - num[栈顶，--] 
	char op[5]; 	//运算符 
	num[0] = 0;		//初始化操作数栈 
	op[0] = 0;		//初始化运算符栈 
	cin>>n;
	int result[n];	//定义结果数组 
	for(int i=0; i<n; ++i){	//循环n次 
		for(int j=0; j<7; ++j){	//读入7个字符 
			if(j%2 == 0){	//操作数进栈 
				cin>>num[++num[0]]; 
				if (op[op[0]] == '-')	//如果运算符栈顶为 - 则将操作数转换 +（-x） 
					num[num[0]] *= -1;
				else if (op[op[0]] == 'x'){	//需要x运算
					temp = num[num[0]] * num[num[0]-1];
					num[--num[0]] = temp;
					--op[0];
				}
				else if(op[op[0]] == '/'){	//需要/运算
					temp = num[num[0]-1] / num[num[0]];
					num[--num[0]] = temp;
					--op[0];
				}
			}
			else{			//运算符进栈 
				cin>>op[++op[0]];
			}			
		} 
		while(op[0] > 0){	//将剩余+号运算完 
				temp = num[num[0]] + num[num[0]-1];
				num[--num[0]] = temp;
				--op[0];
		}
		if(num[1] == 24)	//判定结果 
			result[i] = 1;
		else
			result[i] = 0;
		num[0] = 0;			//初始化操作数栈 
	} 
	for(int i=0; i<n; ++i){	//打印结果 
		if(result[i] == 1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
} 

*/
