#include <bits/stdc++.h>
using namespace std;

typedef struct disk
{
	int no;
	char cont[20481];
}DISK;

int n,s,l,m;
long long b;
DISK * disks;

int getblk(long long b)
{
	if(n==2){
		char ans[9];
		long long st=b*8;
		if(st>=strlen(disks[0].cont)){
			cout<<'-'<<endl;
			return 0;
		} 
		strncpy(ans,disks[0].cont+st,8);
		ans[8]='\0';
		cout<<ans<<endl;
	}
	else
	{
		if(l==n)
		{
			char ans[9];
			long long row=b/(s*n-s),left=b%(s*n-s)+1;
			int pd=n-1-row%n;int ansd=((left-1)/s+pd+1)%(n);
			
			int disklen=strlen(disks[ansd].cont);
			int st=(row*s+(left-1)%s)*8;
			//cout<<row<<' '<<left<<' '<<pd<<' '<<ansd<<' '<<st<<endl;
			if(st>=disklen){
				cout<<'-'<<endl;
				return 0;
			}
			else{
				strncpy(ans,disks[ansd].cont+st,8);
				ans[8]='\0';
				cout<<ans<<endl;
			}
			
		}
	}
	//cout<<
}

int buildmap()
{
	if(n==l){
		
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s>>l;
	disks=(DISK *)malloc(sizeof(disk)*l);
	
	for(int i=0;i<l;i++)
	{
		cin>>disks[i].no;cin>>disks[i].cont;
	}
	
	if(n==2)
	{
		if(l==1){
			disks[l].no=1;strcpy(disks[1].cont,disks[0].cont);
		}
	}
	else{
		buildmap();
	}
	
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>b;
		getblk(b);
	}
	
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

const int maxn = 1000;
const int maxm = 40960;

char disk[maxn+10][maxm*2];
int n,s,l,m;
long long b[1000];

int BuildMatrix()
{
	if( n==2 ){
		return 0;
	}
}

int main()
{
	memset(disk,NULL,sizeof(disk));
	
	cin>>n>>s>>l;
	int i,j,diskno;
	
	for( i=0;i<l;i++)
	{
		cin>>diskno;
		fgets(disk[diskno], maxm*2 + 10, stdin);
	}
	
	cin>>m;
	for( i=0;i<m;i++ )
	{
		cin>>b[i];
	}
	
} 

int xorblk(int x)
{
	int start = Getstart(x);
	int i,count;
	int tmpval=0,tmpval1;
	char tmp[9];
	memset(tmp,NULL,9);
	for( i=0;i<n;i++ ){
		if(disk[i]!=NULL){
			strncpy(tmp,disk[i]+start*8,8);
			if(tmpval==0){
				sscanf(tmp,"%X",&tmpval); 
				tmpval1=tmpval;
			}
			else{
				sscanf(tmp,"%X",&tmpval);
				tmpval1 ^=tmpval;
			}
			count++;
		}
	}
	
	if(count<n-1){
		return 0;
	}
	else{
		return tmpval1;
	}
}




#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
const int maxm = 40960;

string disk[maxn+10];
bool disksig[maxn+10]={0};
char blockread[9];
int n,s,l,m,max_k;
long long b[1000+10];

int Getk(int x)
{
	int y=x/s;
	return y/n;
}

int Getdisk(int x)
{
	int rd=n-Getk(x)%(n+1);
	return (rd+1+(x/s)%n)%(n+1);
}

int Getstart(int x)
{
	return Getk(x)*s+x%s;
}

const string base = "0123456789ABCDEF";

int to_int (char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    else  return ch - 'A' + 10;
}
void _xor (string& ans, string str) {
    for (int i = 0; i < str.size(); i++) {
        int x = to_int(ans[i]);
        int y = to_int(str[i]);
        ans[i] = base[(x ^ y)];
    }
}

string get_xor (int diskno, int _start) {
    string ans(8,'0');
    for (int i = 0; i <= n; i++)
        if (i != diskno)
            _xor(ans, disk[i].substr(_start, 8));
    return ans;
}

int main()
{
//	memset(disk,'\0',sizeof(disk));
//	memset(blockread,'\0',sizeof(blockread));
	
	cin>>n;
	cin>>s;
	cin>>l;
	n-=1;
	
	int i,diskno,bdisk;
	for( i=0;i<l;i++ )
	{
		cin>>diskno;
		cin>>disk[diskno];
		max_k = disk[diskno].size() / 8 / s;
		disksig[diskno]=1;
	}
	
	cin>>m;
	for (i=0;i<m;i++)
	{
		cin>>b[i];
	}
	
	int tmp;
	for (i=0;i<m;i++)
	{
		bdisk=Getdisk(b[i]);
		if (Getk(b[i]) >= max_k){
			cout << "-\n";
			continue;
		}
		else if(disk[bdisk].size()!=0){
			int _start = 8 * (Getk(b[i]) * s + b[i] % s);
            cout << disk[bdisk].substr(_start, 8) << "\n";
			continue;
		}
		else if(disk[bdisk].size() == 0 && l == n){
			int _start = 8 * (Getk(b[i]) * s + b[i] % s);
            cout << get_xor(bdisk, _start) << "\n";
            continue;
		}
		else{
			cout<<'-'<<endl;
		}
	}
	
	return 0;
}
*/
