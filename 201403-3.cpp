// 201403-3

#include <iostream>
#include <string.h>

using namespace std;

bool parasig[27];
bool cmd[27];
int N;

char setting[52];
char cmdinput[21][257];

int Parsesetting()
{
	int i=0;
	while( setting[i] ){
		if( setting[i] == ':'){
			continue;
		}
		else if( setting[i+1]==':' ){
			parasig[setting[i]-'a']=true;
		}
		else if( setting[i+1]!=':' ){
			parasig[setting[i]-'a']=false;
		}
		cmd[setting[i]-'a']=true;
		i++;
	}
	return 0;
}

int ParseLine( int x ){
	char str2[256];
	strcpy(str2,cmdline[x]);
	
	str2 = strchr(str2,' ')+1;
	char cursor;
	cursor = *(str+1);
	char * para;
	
	while( cursor ) {
		if(cmd[cursor-'a']==0){
			break;
		}
		else{
			if(parasig[cursor-'a']==1){
				para = cursor+2;
			}
		}
	}
}

int main()
{
	memset(setting,0,sizeof(setting));
	memset(cmdinput,0,sizeof(cmdinput));
	
	cin>>setting;
	cin>>N;
	
	int i;
	for( i=0;i<N;i++ ){
		gets(cmdinput[i]);
	}
	
	Parsesetting();
}
