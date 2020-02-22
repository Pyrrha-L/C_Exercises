#include <bits/stdc++.h>
using namespace std;

const int textlen = 81;

typedef struct
{
	int lineno;
	char tag[textlen];
	char id[textlen];
	int father;
}TEXT;

int n,m,father2[41]={1,0};
int treemap[101][101]={0};

int Parsetext(int i, char * line,vector<TEXT> &texts)
{
	char line2[textlen];
	strcpy(line2,line);
	
	TEXT * tmp=(TEXT *)malloc(sizeof(TEXT));
	tmp->lineno=i;
	//tmp.id=(char *)malloc(textlen);tmp.tag=(char *)malloc(textlen);
	memset(tmp->id,'\0',textlen);memset(tmp->tag,'\0',textlen);
	
	int j,k;
	for (j=0;line2[j]=='.';j++) { }
	if(j>=2)
	{
		tmp->father=father2[j/2-1];
		father2[j/2]=tmp->lineno;
	}
	
	k=0;
	if(j==0){
		tmp->father=0;
		strcpy(tmp->tag,strlwr(line2));
	}
	
	char *tokenPtr=strtok(line2+j," ");
	strcpy(tmp->tag,strlwr(tokenPtr));
	
	if(	(tokenPtr=strtok(NULL," "))!=NULL )
	{
		strcpy(tmp->id,tokenPtr+1);
	}

 	texts.push_back(*tmp);
}

int BuildTree(vector<TEXT> &texts)
{
	int veclen=texts.size();
	for( int i=0;i<veclen;i++ )
	{
		//cout<<texts[i].father<<' '<<i<<' '<<texts[i].lineno<<' '<<texts[i].id<<endl;
		int tmp=texts[i].father-1;
		if(tmp>=0) treemap[tmp][++treemap[tmp][0]]=i;
	}

	return 0;
}

int SearchTree(char * line,vector<TEXT> &texts, int son, int flag, int * count)
{
	char line2[textlen];
	char tmp[textlen];
	strcpy(line2,line);
	
	char *tokenPtr=strchr(line2,32);
//	cout<<tokenPtr<<'-'<<endl;
	if(tokenPtr) tokenPtr[0]='\0';
	else{
//		cout<<"82:"<<line<<' '<<son<<endl;
		if( flag==1 )
		{
			//cout<<"80:"<<texts[son].tag<<endl;
			if(strcmp(line2,texts[son].tag)==0){
				count[++count[0]]=texts[son].lineno;
			}
		}
		else
		{
			if(strcmp(line2+1,texts[son].id)==0){
				count[++count[0]]=texts[son].lineno;
			}
		}
		return son;
	}

	if(flag==1){
		strcpy(tmp,strlwr(line2));
		if(strcmp(tmp,texts[son].tag)==0){
			for( int j=1;j<=treemap[son][0];j++ )
			{
				SearchTree(tokenPtr+1,texts,treemap[son][j],1,count);
			}
		}

	}
	else{
		strcpy(tmp,line2+1);
		if(strcmp(tmp,texts[son].id)==0){
			for( int j=1;j<=treemap[son][0];j++ )
			{
				SearchTree(tokenPtr+1,texts,treemap[son][j],2,count);
			}
		}
	}
}

int FindRes(char * line,vector<TEXT> texts)
{
	char line2[textlen];
	strcpy(line2,line);
	
	int count[101]={0};
	int veclen=texts.size();
	
	if(strchr(line2,' ')==NULL)
	{
		if(strchr(line2,'#')==NULL)
		{
			strlwr(line2);
		}
		else{
			int k=0;
			while(line2[k])
			{
				line2[k]=line2[k+1];
				k++;
			}
		}
		
		for( int i=0;i<veclen;i++ )
		{
			if(strcmp(texts[i].id,line2)==0||strcmp(texts[i].tag,line2)==0)
			{				
				count[++count[0]]=texts[i].lineno;
			}
		}
	}
	else if(strchr(line2,'#')==NULL)
	{
		for(int i=0;i<n;i++)
		{
			SearchTree(line2,texts,i,1,count);
		}
		
	}
	else{
		for(int i=0;i<n;i++)
		{
			SearchTree(line2,texts,i,2,count);
		}
		
	}
	
	if(count[0]==0){
		cout<<'0'<<endl;
		return 0;
	} 
	
	for( int t=0;t<=count[0];t++ )
	{
		cout<<count[t]<<' ';
	}
	cout<<endl;
	
	return 0;
}
int main()
{
	char * input=(char *)malloc(sizeof(char)*textlen);
	char buff[2];
	vector<TEXT> texts;
	
	scanf("%d %d",&n,&m);
	gets(buff);
	
	int i;
	for( i=1;i<=n;i++ )
	{
		cin.getline(input,textlen);
		Parsetext(i,input,texts);
	}
	
	BuildTree(texts);
	for( i=1;i<=m;i++ )
	{
		cin.getline(input,textlen);
		FindRes(input,texts);
	 } 

}

/*
11 5
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #one
......div
........p #two
p
#subtitle
h3
div p
div div p
*/
