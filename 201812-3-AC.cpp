//#include <iostream>
//#include <list>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//#include <string>
#include <bits/stdc++.h>
using namespace std;

struct IP
{
    string ip;
    int len=0;
    friend bool operator<(const IP &i,const IP &j)
    {
        long long  i1=stoll(i.ip.substr(0,i.ip.find('/')));
        long long  j1=stoll(j.ip.substr(0,j.ip.find('/')));
        if(i1!=j1)
            return i1<=j1;
        else
            return i.len<=j.len;
    }
};
int str_to_int(const string &str)
{
    int num;
    stringstream ss;
    ss<<str;
    ss>>num;
    return num;
}
void format(IP &ip)
{
    int f=ip.ip.find('/');
    string sub;
    int count_dot=0;
    
    if(f!=string::npos)
    {
        //���ݴ泤�� 
        sub=ip.ip.substr(f+1,ip.ip.length()-f-1);
        ip.len=str_to_int(sub);
        
        //ͳ�Ƶ�ĸ��� 
        int count_dot=0;
        sub=ip.ip;
        while((f=sub.find('.'))!=string::npos)
        {
            sub=sub.substr(f+1,sub.length()-f-1);
            ++count_dot;
        }
        //��ȫip 
        if(count_dot!=3)
        {
            ip.ip.erase(ip.ip.find('/'),ip.ip.length()-ip.ip.find('/'));
            for(int i=0;i<3-count_dot;++i)
                ip.ip.append(".0");
            ip.ip.append("/").append(to_string(ip.len));
        }
    }
    else
    {
        sub=ip.ip;
        while((f=sub.find('.'))!=string::npos)
        {
            sub=sub.substr(f+1,sub.length()-f-1);
            ++count_dot;
        }
        if(count_dot!=3)
            for(int i=0;i<3-count_dot;++i)
                ip.ip.append(".0");
        ip.ip.append("/").append(to_string((count_dot+1)*8));
    }
    
    //�洢��׼�͵�ip�е�/len 
    string s=ip.ip.substr(ip.ip.find("/"),ip.ip.length()-ip.ip.find("/"));
    //�洢ip 
    string s1=ip.ip.substr(0,ip.ip.find('/'));
    ip.ip.clear();
    char *s2=new char[s1.size()];//ҪΪs2����ռ��ſɸ�ֵ 
    strcpy(s2,s1.c_str());
    vector<int> v;
    //ȡ����'.'�ָ���� 
    char *p=strtok(s2,".");
    while(p)
    {
        v.push_back(str_to_int(p));
        p=strtok(NULL,".");
    }
    //���2���� 
    string s3;
    for(int i=0;i<v.size();++i)
    {    
        int t=v.at(i);
        while(t)
        {
            s3.append(to_string(t%2));
            t/=2;
        }
    }
    reverse(s3.begin(),s3.end());
    ip.ip.append(s3).append(s);
    delete []s2;
}
bool check(const IP &i,const IP &j)
{
    if(i.len>i.ip.length()||i.len>j.ip.length())
        return false;
    return i.ip.compare(0,i.len,j.ip,0,i.len)==0?true:false;
}
int main()
{
    int n;
    cin>>n;
    
    IP ip;
    list<IP> l;
    //1.��ʽ������;��������������Ͷ���ɱ�׼�ͣ�ip�ö����Ʊ�ʾ 
    while(n--)
    {
        cin>>ip.ip;
        format(ip);
        l.push_back(ip);
    }
    l.sort();
    
    //2.��С���ϲ� 
    for(auto i=l.begin();i!=l.end();)
    {
        list<IP>::iterator next=i;
        ++next;
        if(next==l.end())
            break;
        
        if(check(*i,*next))
            l.erase(next);
        else
            ++i;
    }
    //3.�ϲ�ͬ��
    
    for(auto i=l.begin();i!=l.end();)
    {
        list<IP>::iterator    next=i;
        ++next;
        if(next==l.end())
            break;
        IP ip1=*i;
        IP ip2=*next;
        if(ip1.len==ip2.len&&ip1.len>0&&ip1.ip[ip1.len-1]=='0')
        {
            IP tmp=ip1;
            --(tmp.len);
            if(check(tmp,ip2))
            {
                l.erase(next);
                *i=tmp;
                if(i!=l.begin())
                    --i;
            }
            else
                ++next;
                
        }
        else
            ++i;
    } 
    for(auto i=l.begin();i!=l.end();++i)
        cout<<(*i).ip<<endl;
    return 0;
}
