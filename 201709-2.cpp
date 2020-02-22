#include <bits/stdc++.h>
using namespace std;

const int MAXN=1002;

struct myact
{
    int mytime,ac,key;
    myact() {}
    myact(int t,int a,int k) {mytime=t;ac=a;key=k;}
    bool operator <(const myact& a) const
    {
    	if(mytime!=a.mytime){
    		return mytime > a.mytime;
		}
        else{
        	return ac<a.ac;
		}
    }
};

priority_queue<myact> q[MAXN];
map<int,int> mm;
int N,K,maxs=0,mins=100000;
int keys[1002];

int findspace()
{
//	for(int i=1;i<=N;i++) cout<<keys[i]<<' ';
//	cout<<endl;
	
	for(int i=1;i<=N;i++){
		if(keys[i]==-1) return i;
	}
}

int findkey( int k )
{
//	for(int i=1;i<=N;i++) cout<<keys[i]<<' ';
//	cout<<endl;
	
	for(int i=1;i<=N;i++){
		if(keys[i]==k) return i;
	}
}

int proc()
{
	myact x,y;
	for(int i=mins;i<=maxs;i++)
	{
		if(mm[i]==0) continue;
		
		if(mm[i]>1){
			for(int j=1;j<=N;j++)
			{
				if(!q[j].empty()) x=q[j].top();
				else continue;
				//cout<<"47: "<<j<<' '<<x.key<<' '<<x.ac<<endl;
				if(x.mytime==i&&x.ac==2){
					q[j].pop();
					keys[findspace()]=x.key;
				}
			}
			
			for(int j=1;j<=N;j++)
			{
				if(!q[j].empty()) x=q[j].top();
				else continue;
				
				if(x.mytime==i&&x.ac==1){
					q[j].pop();
					keys[findkey(x.key)]=-1;
				}
			}
			
		//	for(int i=1;i<=N;i++) cout<<keys[i]<<' ';
		//	cout<<endl;
			continue;
		}
		
		for(int j=1;j<=N;j++)
		{
			if(!q[j].empty()) x=q[j].top();
			else continue;
			
			if(x.mytime==i){
				q[j].pop();
				if(x.ac==1)
				{
					keys[findkey(x.key)]=-1;
				//	cout<<keys[x.key]<<' '<<x.mytime<<' '<<x.ac<<' '<<x.key<<endl;
					
				}
				else if(x.ac==2)
				{
					keys[findspace()]=x.key;
				}
			}
		}
		
	//	for(int i=1;i<=N;i++) cout<<keys[i]<<' ';
	//	cout<<endl;
	}
}

int main()
{
	cin>>N>>K;
	
	for(int i=1;i<=N;i++) keys[i]=i;
	
	int key,t1,t2;
	while(K--)
	{
		cin>>key>>t1>>t2;
		if(t1<mins) mins=t1;
		if(t1+t2>maxs) maxs=t1+t2;
		
		if(mm.find(t1)==mm.end()) mm.insert(make_pair(t1,1));
		else mm[t1]++;
		
		if(mm.find(t1+t2)==mm.end()) mm.insert(make_pair(t1+t2,1));
		else mm[t1+t2]++;
		
		q[key].push(myact(t1,1,key));
		q[key].push(myact(t1+t2,2,key));
	}
	
	proc();
	
	for(int i=1;i<=N;i++) cout<<keys[i]<<' ';
	
	return 0;
}

