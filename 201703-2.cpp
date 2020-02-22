#include <bits/stdc++.h>
using namespace  std;

int n,m;

int main()
{
	list<int> myque;
	
	cin>>n;
	for( int i=1;i<=n;i++ )
	{
		myque.push_back(i);
	}
	
	cin>>m;
	int tmp1,tmp2,tmp3,pos;
	list<int>::iterator it;
	for( int i=0;i<m;i++ )
	{
		cin>>tmp1>>tmp2;
		for(it=myque.begin(),tmp3=1;it!=myque.end();it++,tmp3++){
			if(*it==tmp1){
				myque.erase(it);pos=tmp3;
				break;
			}
		}
		
		for(it=myque.begin(),tmp3=1;it!=myque.end();it++,tmp3++){
			if(pos+tmp2==0){
				myque.push_front(tmp1);break;
			}
			if(pos+tmp2==n){
				myque.push_back(tmp1);break;
			}
			if(tmp3==pos+tmp2){
				myque.insert(it,tmp1);break;
			}
		}
		
	}
	
	for(list<int>::iterator it=myque.begin();it!=myque.end();it++){
		cout<<*it<<' ';
	}
	cout<<endl;
}
