#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int x,count;
}num;

bool cmp2(const num &a,const num &b)
{
	if(a.count>b.count){
		return true;
	}
	else if(a.count==b.count){
		return a.x<b.x;
	}
	else{
		return false;
	}
}

int main()
{
	vector<num> mymap;
	int flag[1001]={0};
	vector<num>::iterator it;
	
	int n,x,y=0;
	cin>>n;
	for( int i=0;i<n;i++ )
	{
		cin>>x;
		if(flag[x]==0){
			mymap.push_back({x,1});
			flag[x]=1;
		}
		else{
			for(it=mymap.begin();it!=mymap.end();it++)
			{
				if(it->x==x){
					it->count++;
					break;
				}
			}
		}
	}
	
	sort(mymap.begin(),mymap.end(),cmp2);
	
	for(it=mymap.begin();it!=mymap.end();it++){
		cout<<it->x<<' '<<it->count<<endl;
	}

}
