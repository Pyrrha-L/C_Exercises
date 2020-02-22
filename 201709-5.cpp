#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,M,l,r,v,op;
vector<ll> a;

int main()
{
	cin>>N>>M;
	ll tmp;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		a.push_back(tmp);
	}
	
	for(int i=0;i<M;i++)
	{
		cin>>op;
		if(op==2){
			cin>>l>>r;
			ll sum=0;
			for(int j=l-1;j<r;j++){
				sum+=a[j];
			}
			cout<<sum<<endl;
		}
		else if(op==1){
			cin>>l>>r>>v;
			for(int j=l-1;j<r;j++){
				if(a[j]%v==0) a[j]/=v;
			}
		}
	}
	return 0;
}
