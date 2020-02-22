#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,co=0;
	int a[1002]={0};
	
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	
	int i,j;
	for(i=0;i<n;i++)
	{
		int sum=0;
		for(j=i;j<n;j++)
		{
			if(sum<k){
				sum+=a[j];
			}
			else{
				co++;
				break;
			}
		}
		i=j-1;
	}
	cout<<co+1<<endl;
}
