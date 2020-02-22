#include <bits/stdc++.h>
using namespace std;

int n;
int price[1001];
int price2[1001];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==0){
			price2[i]=(price[i]+price[i+1])/2;
		}
		else if(i==n-1){
			price2[i]=(price[i]+price[i-1])/2;
		}
		else{
			price2[i]=(price[i-1]+price[i]+price[i+1])/3;
		}
		
		cout<<price2[i]<<' ';
	}
	return 0;
}
