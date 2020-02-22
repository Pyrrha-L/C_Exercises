#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[1002]={0};
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	
	int smin=10001;
	for(int i=1;i<n;i++){
		if(abs(a[i]-a[i-1])<smin) smin=abs(a[i]-a[i-1]);
	}
	
	cout<<smin<<endl;
	return 0;
}
