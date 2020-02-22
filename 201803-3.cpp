#include <bits/stdc++.h>
using namespace std; 
//其他合法字符还包括大小写英文字母、阿拉伯数字、减号 -、下划线 _ 和小数点 .

const int length = 101;
int n,m;

typedef struct
{
	char name[length];
	char parts[length][length];
	int limcount;
	int endflag; 
	int pathflag;
}RULE;

RULE rules[length];

int isLegalChar(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='/'||c=='-'||
		c=='_'||c=='.'){
			return 0;
	}
	else{
		return -1;
	}
}

int isStr(char * str1)
{
	char * str2=(char *)malloc(length);
	strcpy(str2,str1);
	int len = strlen(str2);
	
	for( int i=0;i<len;i++ )
	{
		if(isLegalChar(str2[i])||str2[i]=='/'){
			return -1;
		}
	}
	return 0;
}

int isInt(char * str1)
{
	char * str2=(char *)malloc(length);
	strcpy(str2,str1);
	int len = strlen(str2);
	
	for( int i=0;i<len;i++ )
	{
		if(!(str2[i]>='0'&&str2[i]<='9')){
			return -1;
		}
	}
	
	sscanf(str2,"%d",&len);
	//cout<<"58\n"; 
	return len;
}

int isPath(char * str1)
{
	char * str2=(char *)malloc(length);
	strcpy(str2,str1);
	int len = strlen(str2);
	
	for( int i=0;i<len;i++ )
	{
		if(isLegalChar(str2[i])){
			return -1;
		}
	}
	return 0;
}

int Parserule(char * str1,int ruleno)
{
	char * str2=(char *)malloc(length);
	strcpy(str2,str1+1);
	int len = strlen(str2);
	
	if(str2[len-1]=='/'){
		rules[ruleno].endflag=1;
	}
	else{
		rules[ruleno].endflag=0;
	}
	
	const char s[2] = "/";
   	
   	memset(rules[ruleno].parts[rules[ruleno].limcount],'\0',length);
   	char * token=strtok(str2, s);
   	strcpy(rules[ruleno].parts[rules[ruleno].limcount],token);
   	rules[ruleno].limcount++;
   	
   	for( int i=0;token!=NULL;i++ ) {
   		if(i==0){
   			token = strtok(NULL, s);
   			continue;
		}
		memset(rules[ruleno].parts[rules[ruleno].limcount],'\0',length);    	
		strcpy(rules[ruleno].parts[rules[ruleno].limcount],token);
		rules[ruleno].limcount++;
		token = strtok(NULL, s);
   	}
   	
   	rules[ruleno].pathflag=0; 
   	for( int i=0;i<rules[ruleno].limcount;i++ )
   	{
   		if(strcmp(rules[ruleno].parts[i],"<path>")==0){
   			rules[ruleno].pathflag=1;
		}
	}
	return 0;
}

int Parseurl(char * str1)
{
	char * str2=(char *)malloc(length);
	strcpy(str2,str1+1);
	int len = strlen(str2);
	int count=0;
	
	const char s[2] = "/";
   	char strparts[length][length];
   	memset(strparts[count],'\0',length);
   	char * token=strtok(str2, s);
   	strcpy(strparts[count],token);
   	count++;
   	
   	for( int i=0;token!=NULL;i++ ) {
   		if(i==0){
   			token = strtok(NULL, s);
   			continue;
		}
		memset(strparts[count],'\0',length);    	
		strcpy(strparts[count],token);
		count++;
		token = strtok(NULL, s);
   	}
   	
   	int j,flag=0,count2=0;
   	char outparts[length][length];
   	char tmppath[length];
   	for( int i=0;i<n;i++ )
   	{
   		count2=0;
   		memset(outparts,'\0',length*length);
   		if(count!=rules[i].limcount&&rules[i].pathflag==0){
   			continue;
		}
		if(str1[strlen(str1)-1]!='/'&&rules[i].endflag==1&&rules[i].pathflag==0){
			continue;
		}
		
   		for( j=0;j<rules[i].limcount;j++ )
   		{
   			if(strcmp(rules[i].parts[j],"<path>")==0){
				if(isPath(strstr(str1,strparts[j]))!=-1){
					strcpy(outparts[count2++],strstr(str1,strparts[j]));
					flag=1;
					break; 
				}
			}
   			else if(strcmp(rules[i].parts[j],"<int>")==0){
   				if(isInt(strparts[j])!=-1){
   					//itoa(isInt(strparts[j]),outparts[count2++],10);
   					sprintf(outparts[count2++],"%d",isInt(strparts[j]));
					//strcpy(outparts[count2++],itoa(isInt(strparts[j]),);
				}
				else break;
			}
			else if(strcmp(rules[i].parts[j],"<str>")==0){
				if(isStr(strparts[j])!=-1){
					strcpy(outparts[count2++],strparts[j]);
				}
				else break;
			}
			else if(strcmp(rules[i].parts[j],strparts[j])==0){
				continue;
			}
			else{
				break;
			}
		}
		if(j==rules[i].limcount || (rules[i].pathflag==1&&flag==1)){
			//flag=1;
			cout<<rules[i].name;
			for( int k=0;k<count;k++ )
			{
				 
				cout<<' '<<outparts[k];
			}
			cout<<endl;
			return 0;
		}
	}
	
	cout<<"404"<<endl;
	return 0;
}

int main()
{
	cin>>n>>m;
	char tmpline[length];
	
	for( int i=0;i<n;i++ )
	{	
		memset(tmpline,'\0',length);
		cin>>tmpline;
		Parserule(tmpline,i);
		cin>>rules[i].name;
	}
	
	for( int i=0;i<m;i++ )
	{
		memset(tmpline,'\0',length);
		cin>>tmpline;
		Parseurl(tmpline);
	}
	
	return 0;
}
