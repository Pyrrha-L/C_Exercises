#include <bits/stdc++.h>
using namespace std;

const int maxt=667;
const int maxn=10001;
const int maxk=9;

typedef struct{
	int type,from,to;
}mpi;

int T,n;
queue<mpi> mpiq[maxn];

int parseword(char * word,int i)
{
	mpi newmpi;
	if(word[0]=='S') newmpi.type=0;
	else if(word[0]=='R') newmpi.type=1;
	
	newmpi.from=i;
	newmpi.to=atoi(word+1);
	mpiq[i].push(newmpi);
	
	mpi tmp=mpiq[i].back();
	return 0;
}

int parseline(string line, int i)
{
	char line2[50];
	strcpy(line2,line.c_str()); 
	char *tokenPtr=strtok(line2," ");
    while(tokenPtr!=NULL){
        parseword(tokenPtr,i);
        tokenPtr=strtok(NULL," ");
    }
    return 0;
}

int cal()
{
	int flag=0;
	mpi tmp,tmp2;
	
	for(int i=0;i<n;i++)
	{
		if(mpiq[i].empty()) continue;
		
		tmp=mpiq[i].front();
		
		for(int j=i+1;j<n;j++){
			tmp2=mpiq[j].front();
		
			if(tmp2.type+tmp.type==1&&tmp2.from==tmp.to&&tmp2.to==tmp.from){
				mpiq[i].pop();
				mpiq[j].pop();
				flag=1;
				break;
			}
		}
	}
	
	return flag;
}

int main()
{
	cin>>T>>n;
	char c=getchar();
	string line;
	while(T--)
	{
		for(int i=0;i<n;i++)
		{
			while(!mpiq[i].empty()) mpiq[i].pop();
			
			line.clear();
			getline(cin,line);
			parseline(line,i);

		}
		
		while(cal()){
		}
		
		int f=0;
		for(int i=0;i<n;i++)
		{
			if(!mpiq[i].empty()){
				f=1;break;
			}
		}
		
		if(f==0) cout<<'0'<<endl;
		else cout<<'1'<<endl;
	}
	return 0;
}

/*
struct mpi{
	int type,target;
};

int T,N,count2;
mpi mymap[maxn][maxk];
int orderc[maxn];

int subparse(string line1,int i)
{
	int fuc,pno,k;
	if(line1[0]=='S') fuc=1;
	else fuc=2;
	
	sscanf(line1.c_str()+1,"%d",&pno);
	k=orderc[i];
	mymap[i][k].type=fuc;
	mymap[i][k].target=pno;
	count2++;orderc[i]++;
//	cout<<"26:"<<i<<' '<<k<<' '<<mymap[i][k].type<<' '<<mymap[i][k].target<<endl;
}

int parse(string line,int i)
{
	int pos1=0,pos2=0;
	string line1;
	//cout<<"34: "<<line<<endl;
	while((pos1=line.find(' ',pos2+1))!=string::npos){
		line1.clear();
		line1=line.substr(pos2,pos1-pos2);
		//cout<<"28:"<<line1<<endl;
		subparse(line1,i);
		pos2=pos1+1;
	}
	
	line1.clear();line1=line.substr(pos2);//cout<<"33:"<<line1<<endl;
	subparse(line1,i);
}

int initmymap()
{
	count2=0;
	for(int i=0;i<N;i++){
		orderc[i]=0;
		for(int j=0;j<maxk;j++){
			mymap[i][j].target=0;mymap[i][j].type=0;
		}
	}		
}

int getfirst(int n)
{
	for(int i=0;i<maxk;i++)
	{
		if(mymap[n][i].type!=0) return i;
	}
}

int cal()
{
/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<orderc[i];j++)
		{
			cout<<mymap[i][j].type<<' '<<mymap[i][j].target<<' ';
		}
		cout<<endl;
	}
	int tmp1,tmp2,tmp3,count3=0;
	
	while(1){
		for(int i=0;i<N;i++)
		{
			int lim,j=0;lim=orderc[i];
			while(j<lim)
			{
				tmp1=mymap[i][j].type;tmp2=mymap[i][j].target;
				tmp3=getfirst(tmp2); //cout<<i<<' '<<j<<' '<<tmp1<<' '<<tmp2<<' '<<tmp3<<" 73\n";
				if(mymap[tmp2][tmp3].target!=i){
					break;
				}
				else if(mymap[tmp2][tmp3].type+tmp1!=3){
				//	cout<<tmp2<<' '<<tmp3<<' '<<mymap[tmp2][tmp3].type<<' '<<tmp1<<" 78\n";
					cout<<'1'<<endl;return 0;
				}
				else{
					mymap[tmp2][tmp3].type=0;mymap[i][j].type=0;
					orderc[tmp2]--;orderc[i]--;count2-=2;
				}
				j++;
			}
		}
		if(count2!=count3) count3=count2;
		else break;
	}
	
	//cout<<count2<<endl;
	if(count2==0){
		cout<<'0'<<endl;
	}
	else{
		cout<<'1'<<endl; 
	}
	return 0;
}

int main()
{
	char buff[2];
	cin>>T>>N;
	gets(buff);
	string tmp;
	
	for( int i=0;i<T;i++ )
	{
		initmymap();
		for( int j=0;j<N;j++ ){
			getline(cin,tmp);
			parse(tmp,j);
		}
		cal();
	}
}


				for( int k=1;k<=mymap[tmp2][0].type;k++ )
				{
					if( mymap[tmp2][k].target!=i||mymap[tmp2][k].type==0 ) continue;
					else( mymap[tmp2][k].type+tmp1==3 ){
						mymap[i][j].type=0;mymap[tmp2][k].type=0;count2-=2;
						break;
					}
				}
				
	
	vector<mpi>::iterator it=mpiq.begin();
	vector<mpi>::iterator it2=mpiq.end();
	
	for(;it!=mpiq.end();it++){
		if(it2->from!=newmpi.from){
			if(it==mpiq.begin()&&it->type+newmpi.type==1
			&&it->from==newmpi.to&&it->to==newmpi.from){
			mpiq.erase(it);
			return 0;
			}
		
			if(it!=mpiq.begin()&&it->type+newmpi.type==1
			&&it->from==newmpi.to&&it->to==newmpi.from
			&&(it-1)->from!=it->from){
			mpiq.erase(it);
			return 0;
			}
		}
		
	}
	

2 3
R1 S1
R2 S0 R0 S2
S1 R1
R1
R2 S0 R0
S1 R1

3 2
R1 S1
S0 R0
R1 S1
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0

1 2
R1 S1 R1 S1 R1 S1
S0 R0 S0 R0 S0 R0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0
*/
