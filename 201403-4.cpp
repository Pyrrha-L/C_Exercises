#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

const int MAXN = 200;

struct {
	long long x,y;
}coord[MAXN+1];

struct status{
	long long x,y;
	long stepk,kcount;
};

int n,m,k;
long r;
int map[101][101] = {0};
int reachable[101][101] = {0};
int startp[2];
int endp[2];

double CalDist( int x1, int y1, int x2, int y2 )
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool visited[MAXN+1];

int bfs2( int n,int m,int k,int begin,int end,long long r )
{
	int max;
	
	memset(visited,false,sizeof(visited));
	
	status start,front,v;
	start.x = coord[begin].x;
	start.y = coord[begin].y;
	start.kcount=0;
	start.stepk=0;
	
	queue<status> q;
	q.push(start);
	
	visited[begin]=true;
	
	while(!q.empty()){
		front = q.front();
		q.pop();
		
		if( front.x = coord[end].x && front.y = coord[end].y ){
			return front.stepk-1;
		}
		
		if( front.kcount == k ){
			max = n;
		}
		else{
			max = n+m;
		}
		
		for( int i=0;i<max;i++ ){
			if( visited[i] ) continue;
			
			if( (front.x-coord[i].x)*(front.x-coord[i].x)+(front.y-coord[i].y)*(front.x-coord[i].y)>r*r){
				continue;
			}
			else{
				visited[i]=true;
				
				v.x = coord[i].x;
				v.y = coord[i].y;
				v.stepk = front.stepk+1;
				
				if( i<n ){
					v.kcount = front.kcount;
				}
				else{
					v.kcount = front.kcount+1;
				}
				
				q.push(v);
			}
		}
	}
	
	return 0;
}

int BFS(int x,int y)
{
	int i,j;
	for( i=-r;i<r;i++ ){
		for( j=-r;j<r;j++ ){
			if( CalDist(x,y,x+i,y+j) <= r ){
				reachable[x+i][y+j] = 1;
			}
		}
	}
}

int main()
{
	int k2,tmpx,tmpy;
	
	cin>>n;
	cin>>m;
	cin>>k;
	cin>>r;
	
	int i,j;
	for( i=0;i<n;i++ ){
		cin>>tmpx>>tmpy;
		if( i==0 ){
			startp[0]=tmpx;
			startp[1]=tmpy;
		}
		if( i==1 ){
			endp[0]=tmpx;
			endp[1]=tmpy;
		}
		map[tmpx][tmpy] = 1; // ��ʾ����·���� 
	}
	
	for(i=0;i<m;i++ ){
		cin>>tmpx>>tmpy;
		map[tmpx][tmpy] = 2; // ��������·���� 
	}
}

/* AC */

/* CCF201403-4 �������� */
/* 
#include <iostream>
#include <cstring>
#include <queue>
 
using namespace std;
 
const int MAXN = 100 + 100;
 
struct {
    long long x, y;
} coord[MAXN+1];
 
struct status {
    long long x, y;
    int step, kcount;
};
 
bool visited[MAXN+1];
 
int dfs(int n, int m, int k, int begin, int end, long long r)
{
    int max;
 
    // ������ʼ��
    memset(visited, false, sizeof(visited));
 
    // ���ø����
    status start, front, v;
    start.x = coord[begin].x;
    start.y = coord[begin].y;
    start.step = 0;
    start.kcount = 0;
    queue<status> q;
    q.push(start);
 
    // ���ø����Ϊ�Ѿ����ʹ�
    visited[begin] = true;
 
    while(!q.empty()) {
        front = q.front();
        q.pop();
 
        // �����յ������
        if(front.x == coord[end].x && front.y == coord[end].y)
            return front.step - 1;
 
        // �����������ӵ�·����
        if(front.kcount == k)
            max = n;
        else
            max = n + m;
        for(int i=0; i<max; i++) {
            // ���ʹ�������������
            if(visited[i])
                continue;
 
            // �ж���һ��·�����������Ƿ��ڰ뾶r֮��, ���ڰ뾶֮�����������ڰ뾶֮�����������
            if((front.x - coord[i].x) * (front.x - coord[i].x) + (front.y - coord[i].y) * (front.y - coord[i].y) > r * r)
                continue;
            else {
                // ��i��·������Ϊ�Ѿ����ʹ�
                visited[i] = true;
 
                // ���㲽�������ҽ���i��·�����������
                v.x = coord[i].x;
                v.y = coord[i].y;
                v.step = front.step + 1;
                if(i >= n)
                    v.kcount = front.kcount + 1;
                else
                    v.kcount = front.kcount;
                q.push(v);
            }
        }
    }
 
    return 0;
}
 
int main()
{
    int n, m, k;
    long long r;
 
    // ��������
    cin >> n >> m >> k >> r;
    for(int i=0; i<n+m; i++)       // n��·������λ�ã����������m��·������λ��
        cin >> coord[i].x >> coord[i].y;
 
    // BFS
    int ans = dfs(n, m, k, 0, 1, r);
 
    // ������
    cout << ans << endl;
 
    return 0;
}
*/
/*
�������ݣ�
5 3 1 3
0 0
5 5
0 3
0 5
3 5
3 3
4 4
3 0
2
10 1 1 2
0 0
3 1
-2 0
-2 2
-2 4
-2 6
0 6
2 6
2 4
2 2
2 0
1
10 1 1 2
0 0
3 1
-2 0
-2 2
-2 4
-2 6
0 6
2 6
2 4
2 2
3 0
8
6 3 2 50000000
0 0
50000000 100000000
100000000 100000000
100000000 0
100000000 50000000
50000000 0
-100000000 50000000
0 50000000
0 100000000
2
*/

