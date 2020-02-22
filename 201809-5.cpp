#include <bits/stdc++.h>
using namespace std;

const long long Q=998244353;
long long l,m,r;

int main()
{
	cin>>m>>l>>r;
	long long tmp;
	
	vector<long long>k;
	vector<long long>a;
	for(long long i=0;i<m;i++){
		cin>>tmp;
		k.push_back(tmp);
	}
	
	a.push_back(1);
	
	for(long long i=1;i<m;i++)
	{
		tmp=0;
		for(long long j=0;j<i;j++){
			//cout<<"25:"<<k[j]<<' '<<i-j<<endl;
			tmp+=k[j]*a[i-j-1];
			//cout<<tmp<<endl;
		}
		
		a.push_back((tmp)%Q);
	}
	
	for(long long i=m;i<=r;i++){
		tmp=0;
		for(long long j=0;j<m;j++){
			tmp+=k[j]*a[i-j-1];
		}
		a.push_back((tmp)%Q);
	}
	
	for(long long i=l;i<=r;i++)
	{
		cout<<a[i]<<endl;
	}
	
}
