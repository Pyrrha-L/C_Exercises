#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tmp1,tmp2,ans,n;
	tmp2=0;ans=0;n=1;
	while(cin>>tmp1)
	{
		if(tmp1==1){
			n=1;
			ans+=1;
		}
		else if(tmp1==2){
			if(tmp2==0||tmp2==1){
				ans+=2;
			}
			else{
				ans+=tmp2*(++n);
			}
		}
		else{
			break;
		}
		
		tmp2=tmp1;
	}
	cout<<ans;
}
