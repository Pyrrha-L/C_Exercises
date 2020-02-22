#include <bits/stdc++.h>
using namespace std;

char * months[13] ={"0","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug",
"Sep","Oct","Nov","Dec"};
char * weeks[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

typedef struct{
	int ti[5][61];//mi,hr,dom,mo,dow
	string cmd;
}CMD;

typedef struct{
	int ti[5];//yr,mo,day,hr,mi;
}TIMESTAMP;

vector<TIMESTAMP> timevec;
vector<CMD> mycmds;

bool Runyear(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0) return true;
	else return false;
}

int finddaybyname(int flag, char * name)
{
	if(flag==1){ //month 
		for(int i=1;i<13;i++){
			if(strcmp(name,months[i])==0) return i;
		} 
	}
	else{
		for(int i=0;i<7;i++){
			if(strcmp(name,weeks[i])==0) return i;
		}
	}
	return -1;
}

int getweekday(int yr,int mo,int day)
{
	int yr1,mo1,day1,dayc=0;
	for(yr1=1970;yr1<yr;yr1++){
		if(Runyear(yr1)) dayc+=366;
		else dayc+=365;
	}
	
	for(mo1=1;mo1<mo;mo1++){
		if(mo1==1||mo1==3||mo1==5||mo1==7||mo1==8||mo1==10||mo1==12) dayc+=31;
		else if(mo1==2&&Runyear(yr)) dayc+=29;
		else if(mo1==2&&Runyear(yr)==false) dayc+=28;
		else dayc+=30;
	}
	
	for(day1=1;day1<=day;day1++)
	{
		dayc++;
	}
	
	int tmp=(dayc%7+4))%7;
	return tmp;
}

int parsetime(string str)
{
	TIMESTAMP mytime;
	string subline;
	stringstream ss;
	
	for(int i=0;i<5;i++){
		subline.clear();
		ss.clear(); 
		if(i==0){
			subline=str.substr(0,4);ss<<subline;ss>>mytime.ti[0];
		}
		else{
			subline=str.substr((i-1)*2+4,2);cout<<subline<<endl;ss<<subline;ss>>mytime.ti[i];
		}
	}
	timevec.push_back(mytime);
	
	//201711120036
}

int setall(int i,CMD &mycmd)
{
	if(i==0){
		for(int k=0;k<60;k++) mycmd.ti[0][k]=1;
	}
	else if(i==1){
		for(int k=0;k<24;k++) mycmd.ti[1][k]=1;
	}
	else if(i==2){
		for(int k=1;k<=31;k++) mycmd.ti[2][k]=1;
	}
	else if(i==3){
		for(int k=1;k<=12;k++) mycmd.ti[3][k]=1;
	}
	else if(i==4){
		for(int k=0;k<7;k++) mycmd.ti[4][k]=1;
	}
	else{
		return -1;
	}
	return 0;
}

int comma(int i,string str){
	
}

int sub(int i,string str){
	
}

int parsecmd(string str)
{
	CMD mycmd;
	int i=0,tmp;
	string subline;
	stringstream ss;
	while(ss<<str){
		subline.clear();ss.clear();
		ss>>subline;
		
		if(subline.compare('*')==0){
			setall(i);
		}
		
		if(subline.find(',')!=string::npos){
			comma(i,subline);
		}
		
		if(subline.find('-')!=string::npos){
			sub(i,subline);
		}
		
		ss>>tmp;
		mycmd.ti[i][tmp]=1;
		
		if(i==5) mycmd.cmd(subline);
		i++;
	}
	
	mycmds.push_back(mycmd);
}

int check(int yr,int mo,int day,int hr,int mi)
{
	int vecsize=mycmds.size();
	int newti[5];
	newti[0]=mi;newti[1]=hr;newti[2]=day;newti[4]=getweekday(yr,mo,day);
	newti[3]=mo;
	int flag=1;
	for(int i=0;i<vecsize;i++)
	{
		flag=1;
		for(int j=0;j<5;j++){
			if(mycmds[i].ti[j][newti[j]]==0){
				flag=0;
				break;
			}
		}
		
		if(flag) {
			printf("%d%02d%02d%02d%02d",yr,mo,day,hr,mi);
			cout<<' '<<mycmds[i].cmd;
		}
	}
}

int proc()
{
	int yr1,mo1,day1,hr1,mi1,yr2,mo2,day2,hr2,mi2;
	
	yr1=timevec[0].ti[0];
	yr2=timevec[1].ti[0];
	for(int yr=yr1;yr<=yr2;yr++)
	{
		if(yr==timevec[0].ti[0]) mo1=timevec[0].ti[1];
		else mo1==1;
		if(yr==timevec[1].ti[0]) mo2=timevec[1].ti[1];
		else mo1==12;
		
		for(int mo=mo1;mo<=mo2;mo++){
			
			if(yr==timevec[0].ti[0]&&mo==timevec[0].ti[1]) day1=timevec[0].ti[2];
			else day1=1;
			if(yr==timevec[1].ti[0]&&mo==timevec[1].ti[1]) day2=timevec[1].ti[2];
			else {
				if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12) day2=31;
				else if(mo==2&&Runyear(yr)) day2=29;
				else if(mo==2&&Runyear(yr)==false) day2=28;
				else day2+=30;
			}
			
			for( int day=day1;day<=day2;day++ ){
				if(yr==timevec[0].ti[0]&&mo==timevec[0].ti[1]&&
				day==timevec[0].ti[2]) hr1=timevec[0].ti[3];
				else hr1=0;
				
				if(yr==timevec[1].ti[0]&&mo==timevec[1].ti[1]&&
				day==timevec[1].ti[2]) hr2=timevec[1].ti[3];
				else hr2=23;
				
				for(int hr=hr1;hr<=hr2;hr++){
					if(yr==timevec[0].ti[0]&&mo==timevec[0].ti[1]&&
					day==timevec[0].ti[2]&&hr==timevec[0].ti[3]) mi1=timevec[0].ti[4];
					else mi1=0;
					
					if(yr==timevec[1].ti[0]&&mo==timevec[1].ti[1]&&
					day==timevec[1].ti[2]&&hr==timevec[1].ti[3]) mi2=timevec[1].ti[4];
					else mi2=59;
					
					for(int mi=mi1;mi<mi2;mi++){
						check(yr,mo,day,hr,mi);
					}
				}
			}
		}
	}
}

int main()
{
	int s;
	string tbegin,tend,mycmd;
	
	cin>>s;
	cin>>tbegin>>tend;
	parsetime(tbegin);parsetime(tend);
	
	//for(int i=0;i<5;i++) cout<<timevec[1].ti[i]<<' ';

	while(s--)
	{
		getline(cin,mycmd);
		parsecmd(mycmd);
	}
	
	proc();
	
}
