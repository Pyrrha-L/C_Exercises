#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
using namespace std;
unsigned char C[1080][1920][3];//C[n][m][Pixel:RGB] ��ʾԭͼƬ�ڵ�n��m�е�������ɫ 
inline unsigned char getPixel(const char&a,const char&b){//��16����������ת��Ϊ10���Ƶ�char 
	return char((isalpha(a)?(10+a-'a'):(a-'0'))*16+(isalpha(b)?(10+b-'a'):(b-'0')));
}
inline void outChar(const unsigned char&ch){//��������ʽ�����ַ� 
	cout<<"\\x"<<hex<<uppercase<<setw(2)<<int(ch);
}
inline void outStr(const string& str){//��������ʽ�����ַ��� 
	int i = 0;
	for( i;i<str.length();i++){
		outChar(str[i]);
	}
	//for(const char&c:str)outChar(c);
}
inline void outPixel(int i){//��������ʽ�������� 
	vector<int> v;
	if(i==0)v.push_back(0);
	while(i>0) v.push_back(i%10),i/=10;//���Ƚ�����λ���ָ� ����255 �ָ�Ϊ 2��5��5������ 
	for(i=v.size()-1;i>-1;--i) outChar(char('0'+v[i]));//���ÿһλ 
}
#include<fstream> 
int main(){
	int m,n,p,q,_B;// W H 
	//ifstream cin("C:\\Users\\Isidore\\Desktop\\out.txt");
	cin>>m>>n>>p>>q,_B=p*q,cout.fill('0');
	string s;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>s;
			switch(s.size()){//��sͳһ��ʽ��Ϊ #abcdef 
				case 2://#a -> #aaaaaa 
					s=s+string(5,s[1]);
					break;
				case 4://#abc -> #aabbcc
					s="#"+string(2,s[1])+string(2,s[2])+string(2,s[3]);
					break;
			}
			for(int k=0;k<3;++k){
				C[i][j][k]=getPixel(tolower(s[k+k+1]),tolower(s[k+k+2]));
				printf("41:%d ",C[i][j][k]);
			}
			cout<<'\n';
		}
	}
	int R=0,G=0,B=0,r=0,g=0,b=0;
	for(int i=0;i<n;i+=q){//��n/q���ַ����� 
		for(int j=0;j<m;j+=p){//ÿ�ַ����й�m/p�� 
			R=0,G=0,B=0;//���´�������i��j�ε��ַ���
			for(int k=i,nk=k+q;k<nk;++k)
				for(int l=j,nl=j+p;l<nl;++l)
					R+=C[k][l][0],G+=C[k][l][1],B+=C[k][l][2];
			R/=_B,G/=_B,B/=_B;//��ƽ��ֵ
			//cout<<endl<<"57:"<<i<<' '<<j<<endl;
			//cout<<"58:"<<R<<' '<<G<<' '<<B<<endl;
			if(!(R==r&&G==g&&B==b)){//����������һ�ε���ɫ��ͬ 
				if(R==0&&G==0&&B==0)//�����Ĭ��ֵ��ͬ 
					outStr(string(1,char(27))+"[0m");
				else//������ɫ���� 
					outStr(string(1,char(27))+"[48;2;"),outPixel(R),outChar(';'),outPixel(G),outChar(';'),outPixel(B),outChar('m');
				r=R,g=G,b=B;//��¼�ϴε���ɫ 
			}
			outChar(' ');//��� (n*m)/(p*q) ���ո� 
		}
		if(R!=0||G!=0||B!=0) outStr(string(1,char(27))+"[0m");//��β�ж��Ƿ���Ҫ������ɫ 
		r=g=b=0;//����Ĭ����ɫ 
		outChar('\n');//���n/q���س� 
	}
	return 0;
}

