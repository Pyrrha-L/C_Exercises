#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <bitset>
using namespace std;

typedef struct{
	unsigned long long IPline;
	unsigned long long IP[4];
	int prefix;
	int valid;
}IPNODE;

const int iplen = 25;
const int maxip = 1000002;
int IPcount=0;
IPNODE IPs[maxip];
int n;

bool Comp(IPNODE c,IPNODE d)
{
/*	for( int i=0;i<4;i++ )
	{
		if(c.IP[i]<d.IP[i]){
			return true; 
		}
	}
*/	if(c.IPline<d.IPline) return true;
	else if(c.IPline==d.IPline) {
		return c.prefix<d.prefix;
	}
	else{
		return false;
	}
}

void printIP(IPNODE IP2)
{
	for(int i=0;i<3;i++) cout<<IP2.IP[i]<<'.';
	cout<<IP2.IP[3]<<'/'<<IP2.prefix<<endl;//' '<<IP2.valid<<
}

int parseIP(char * IPstr)
{
	char * IPstr2 = (char *)malloc(sizeof(char)*iplen);
	strcpy(IPstr2,IPstr);
	int i,IPs2,perf;
	i=0;IPs2=0;perf=0;
	
	while(IPstr2[i]){
		if(IPstr2[i]=='.'){
			IPs2++;
		}
		if(IPstr2[i]=='/'){
			perf++;
		}
		i++;
	}
	
	if(IPs2==3&&perf==1){
		sscanf(IPstr2,"%d.%d.%d.%d/%d",&IPs[IPcount].IP[0],&IPs[IPcount].IP[1],
			&IPs[IPcount].IP[2],&IPs[IPcount].IP[3],&IPs[IPcount].prefix);
	}
	else if(IPs2==2&&perf==1){
		sscanf(IPstr2,"%d.%d.%d/%d",&IPs[IPcount].IP[0],&IPs[IPcount].IP[1],
			&IPs[IPcount].IP[2],&IPs[IPcount].prefix);
		IPs[IPcount].IP[3]=0;
	}
	else if(IPs2==1&&perf==1){
		sscanf(IPstr2,"%d.%d/%d",&IPs[IPcount].IP[0],&IPs[IPcount].IP[1],
			&IPs[IPcount].prefix);
		IPs[IPcount].IP[3]=0;IPs[IPcount].IP[2]=0;
	}
	else if(IPs2==0&&perf==1){
		sscanf(IPstr2,"%d/%d",&IPs[IPcount].IP[0],
			&IPs[IPcount].prefix);
		IPs[IPcount].IP[3]=0;IPs[IPcount].IP[2]=0;IPs[IPcount].IP[1]=0;
	}
	else if(IPs2==3&&perf==0){
		sscanf(IPstr2,"%d.%d.%d.%d",&IPs[IPcount].IP[0],&IPs[IPcount].IP[1],
			&IPs[IPcount].IP[2],&IPs[IPcount].IP[3]);
		IPs[IPcount].prefix=32;
	}
	else if(IPs2==2&&perf==0){
		sscanf(IPstr2,"%d.%d.%d",&IPs[IPcount].IP[0],&IPs[IPcount].IP[1],
			&IPs[IPcount].IP[2]);
		IPs[IPcount].IP[3]=0;IPs[IPcount].prefix=24;
	}
	else if(IPs2==1&&perf==0){
		sscanf(IPstr2,"%d.%d",&IPs[IPcount].IP[0],&IPs[IPcount].IP[1]);
		IPs[IPcount].IP[3]=0;IPs[IPcount].IP[2]=0;IPs[IPcount].prefix=16;
	}
	else if(IPs2==0&&perf==0){
		sscanf(IPstr2,"%d",&IPs[IPcount].IP[0]);
		IPs[IPcount].IP[3]=0;IPs[IPcount].IP[2]=0;IPs[IPcount].IP[1]=0;IPs[IPcount].prefix=8;
	}
	IPs[IPcount].valid=1;
	IPs[IPcount].IPline=IPs[IPcount].IP[0]*1000000000+IPs[IPcount].IP[1]*1000000+IPs[IPcount].IP[2]*1000+IPs[IPcount].IP[3];

	IPcount++;
}

unsigned long long * getmatch(int i)
{
	int pref = IPs[i].prefix;
	unsigned long long mask=((unsigned long long)-1)<<(32-pref);
	unsigned long long tmp[5],ans=0;
	for(int j=1;j<=4;j++)
	{
		tmp[j]=(IPs[i].IP[j-1]&((mask<<((j-1)*8))>>24));
		cout<<bitset<8>(tmp[j])<<' ';
	}
	cout<<endl;
	
	tmp[0]=pref;
	return tmp;
}

void step2merge()
{
	unsigned long long * matchi,* matchj;
	
	for(int i=0;i<n-1;i++)
	{
		if(IPs[i].valid==1){
			matchi = getmatch(i);
		}	
		else{
			continue;
		}
		for(int j=i+1;j<n;j++)
		{
			if( IPs[j].valid==0 ){
				continue;
			}
			else{
				matchj=getmatch(j);
				int flag=0;
				for( int k=1;k<=4;k++ )
				{
					if(matchj[k]==matchi[k]){
						flag=1;
						break;
					}
				}
				if(flag==0&&matchj[0]<matchi[0]){
					flag=1;
				}
				if(flag==1){
					IPs[j].valid=0;
				}
			}
		}
	}
}

int main()
{
	char * IPtmp=(char *)malloc(sizeof(char)*iplen);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>IPtmp;
		parseIP(IPtmp);
	}
	sort(IPs,IPs+IPcount,Comp);
	for(int i=0;i<n;i++){
		if(IPs[i].valid) printIP(IPs[i]);
	}
	step2merge();
	for(int i=0;i<n;i++){
		if(IPs[i].valid) printIP(IPs[i]);
	}
}

/*
10
101.6.6.0/24
101.6.6/23
101.8
1/32
101.6.6.0
101.6
1
101.6.7.0/24
101.5.6/23
2

2
10/9
10.128/9
*/
