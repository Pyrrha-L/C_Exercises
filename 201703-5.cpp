#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, A, B, Q, X0; 


ll GetXi(ll x)
{
	return (A*x+B)%Q;
}

int main()
{
	cin>>n>>m>>A>>B>>Q>>X0;
	
	if(n==2){
		ll sum=0,tmp=X0;
		for(int i=0;i<m;i++){
			tmp=GetXi(tmp);
			sum+=tmp;
		}
		cout<<sum<<endl;return 0;
	}
	
	if(m==2){
		ll min1=-1,min2=-1,tmp=X0;
		ll col1[1002]={0},col2[1002]={0},row[1002]={0};
		for(int i=0;i<(n-1)*2;i++){
			tmp=GetXi(tmp);
			if(i%2==0){
				col1[++col1[0]]=tmp;
				//if(min1==-1||tmp<min1) min1=tmp;
			}
			if(i%2==1){
				col2[++col2[0]]=tmp;
				//if(min2==-1||tmp<min2) min2=tmp;
			}
		}
		
		for(int i=0;i<n-2;i++)
		{
			tmp=GetXi(tmp);
			row[++row[0]]=tmp;
		}
		
		
		cout<<min1+min2<<endl;return 0;
	}
} 
