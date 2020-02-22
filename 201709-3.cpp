#include <bits/stdc++.h>
using namespace std;

struct kv{
	string cont;
	int type,vnum,vtype;
};

int n,m;
vector<kv> conts;
stack<string> bracs;
string json;

int proc(string str)
{
	string::iterator it;
    for (it = str.begin(); it < str.end(); it++)
    {
        if (*it == ' ')
        {
            str.erase(it);
            it--;
        }
    }
    
    int pos1=0,pos2=-1,count=0,count2=0;
    kv u;
    //cout<<str<<endl;
    while( (pos1=str.find('"',pos2+1))!=string::npos )
    {
		pos2=str.find('"',pos1+1);
		while(str[pos2-1]=='\\'){
			pos2=str.find('"',pos2+1);
		} 
		
		string tmp(str,pos1+1,pos2-pos1-1);
		
		//cout<<tmp<<endl;
		
		u.cont=tmp;
		if(count==0) u.type=0;
		else if(conts[count-1].type==0) u.type=1;
		else if(conts[count-1].type==1||conts[count-1].type==2) u.type=0;
		
		if(count2!=0){
			count2++;
			conts[count-count2+1].vnum++;
		}
		
		if(str[pos2+2]=='{'){
			u.type=2;u.vnum=0;count2=1;
		}
		
		if(str[pos2+1]=='}') count2=0;
		
		conts.push_back(u);
		count++;
	}
	
	vector<kv>::iterator it2;
	for(it2 = conts.begin();it2!=conts.end();it2++)
	{
		for (it=it2->cont.begin(); it!=it2->cont.end(); it++)
    	{
        	if (*it == 92&&(*(it+1) == 92||*(it+1)== '"'))
        	{
        		
            	it2->cont.erase(it);
            	it--;
        	}
    	}
		//cout<<it2->cont<<' '<<it2->type<<endl;
	} 
}

int anal(string query)
{
	string subq,subq2;
	int pos1=0,flag=0;
	if((pos1=query.find("."))!=string::npos)
	{	
		flag=1;
		subq=query.substr(0,pos1);
		subq2=query.substr(pos1+1);
	}
	else{
		subq=query;
	}
	
	if(flag==0)
	{
		vector<kv>::iterator it;
		for( it=conts.begin();it!=conts.end();it++ )
		{
		//	cout<<query<<' '<<it->cont<<endl;
			if(it->cont.compare(query)==0)
			{
				if(it->type==0) {
					cout<<"STRING "<<(it+1)->cont<<endl;break;
				}
				else if(it->type==2){
					cout<<"OBJECT"<<endl;break;
				}
			}
		}
		
		if(it==conts.end()) cout<<"NOTEXIST"<<endl;
	}
	else
	{
		vector<kv>::iterator it;
		int find=0;
		//cout<<"115:"<<subq<<' '<<subq2<<endl;
		for( it=conts.begin();it!=conts.end();it++ )
		{
			if(it->cont.compare(subq)==0&&it->type==2)
			{
				for( int i=1;i<=it->vnum;i++ ){
					//cout<<(it+i)->cont<<' '<<(it+i)->type<<endl;
					if( (it+i)->cont.compare(subq2)==0&&(it+i+1)->type==1 ){
						cout<<"STRING "<<(it+i+1)->cont<<endl;find=1;break;
					}
				}
			}
		}
		
		if(find==0) cout<<"NOTEXIST"<<endl;
	}
}

int main()
{
	string tmp;
	char buff[80];
	cin>>n>>m;
	gets(buff);
	for(int i=0;i<n;i++)
	{
		tmp.clear();
		getline(cin,tmp);
		if(json.size()==0){
			json=tmp;
		}
		else{
			json.append(tmp);
		}
	}
	
	//cout<<json<<endl;
	proc(json);
	
	string query;
	for(int i=0;i<m;i++)
	{
		cin>>query;
		anal(query);
	} 
}
