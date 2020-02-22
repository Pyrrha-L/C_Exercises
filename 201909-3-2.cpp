#include <bits/stdc++.h>
using namespace std;

const int maxm=1922;
const int maxn=1082;

struct apix
{
	int rgb[3]={0};	
};

apix raw[maxm][maxn];
vector<apix> trans;
int m,n,p,q;
string bg("\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B");
string reset("\\x1B\\x5B\\x30\\x6D");
string ent("\\x0A");
string spa("\\x20");
string fen("\\x3B");
string lem("\\x6D");
 
int procraw( string color, int i, int j)
{
	if(color.size()==7){
		for(int k=0;k<3;k++)
		{
			string tmp(color,k*2+1,2);
			sscanf(tmp.c_str(),"%x",&raw[i][j].rgb[k]);
		}
	}
	else if(color.size()==4){
		for(int k=0;k<3;k++)
		{
			string tmp(color,k+1,1);
			sscanf(tmp.c_str(),"%x",&raw[i][j].rgb[k]);
			raw[i][j].rgb[k]+=raw[i][j].rgb[k]*16;
		}
	}
	else if(color.size()==2){
		for(int k=0;k<3;k++)
		{
			string tmp(color,1,1);
			sscanf(tmp.c_str(),"%x",&raw[i][j].rgb[k]);
			raw[i][j].rgb[k]+=raw[i][j].rgb[k]*16;
		}
	}
	
//	for(int k=0;k<3;k++)
//	{
//		cout<<raw[i][j].rgb[k]<<' ';
//	}
//	cout<<endl;

}

int getp(int i,int j)
{
	int sum[3]={0};
	for( int i2=i*q;i2<i*q+q;i2++ )
	{
		for( int j2=j*p;j2<j*p+p;j2++ )
		{
			for( int k=0;k<3;k++ )
			{
				//cout<<k<<' '<<i2<<' '<<j2<<' '<<raw[i2][j2].rgb[k]<<endl;
				sum[k]+=raw[i2][j2].rgb[k];
			}
		}
	}
	int fflag=0,rflag=0;
	apix tmp;
	for( int k=0;k<3;k++ )
	{
		tmp.rgb[k]=sum[k]/(q*p);
		//cout<<endl<<"75:"<<tmp.rgb[k]<<endl;
	}
	apix ftmp;
	
	if(!trans.empty()){
		ftmp=trans.front();
		if(ftmp.rgb[0]==tmp.rgb[0]&&ftmp.rgb[1]==tmp.rgb[1]&&ftmp.rgb[2]==tmp.rgb[2]){
			fflag=1;
		}
	}
	
	trans.push_back(tmp);
	
	if(tmp.rgb[0]==0&&tmp.rgb[1]==0&&tmp.rgb[2]==0){
		rflag=1;
	}
	
	if(fflag==1){
		cout<<spa;
	}
	else if(rflag==1&&i!=0){
		//cout<<"94"<<endl;
		cout<<reset<<spa;
	}
	else if(rflag==1&&i==0){
		cout<<spa;
	}
	else{
		cout<<bg;
		for( int k=0;k<3;k++ )
		{
			cout.setf(ios::uppercase);
			
			vector<int> v;
			if(tmp.rgb[k]==0)v.push_back(0);
			while(tmp.rgb[k]>0) v.push_back(tmp.rgb[k]%10),tmp.rgb[k]/=10;
			
			for(int i2=v.size()-1;i2>-1;--i2){
				cout<<"\\x3"<<v[i2];
			}
			//if(tmp.rgb[k]/(16*16)!=0) cout<<"\\x3"<<tmp.rgb[k]/(16*16);
			//cout<<"\\x3"<<tmp.rgb[k]%16;
			if(k==2) cout<<lem;
			else cout<<fen;
		}
		cout<<spa;
	}
	
	if( j==m/p-1 ){
		if( i==n/q-1&&rflag==0 ){
			cout<<reset<<ent;
		}
		else{
			cout<<ent;
		}
	}
	
}

int main()
{
	cin>>m>>n>>p>>q;
	string color;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) //¿í£¬ÁÐ 
		{
			color.clear();
			cin>>color;
			procraw(color,i,j);
		}
	}
	
	for(int i=0;i<n/q;i++)
	{
		for(int j=0;j<m/p;j++)
		{
			getp(i,j);
		}
	}
}
