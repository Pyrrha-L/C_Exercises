#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

#define RMAX 50
#define CMAX 50

char map[RMAX+1][CMAX+1];
int R,C;
int Sr,Sc;
int Tr,Tc;
int Reachable[RMAX+1][CMAX+1] = {0};

int Init()
{
	memset(map,NULL,sizeof(char)*(RMAX+1)*(CMAX+1));
	
	return 0;
 }

int Input()
{
	int i,j;
	
	scanf("%d %d",&R,&C);
	
	for( i=0;i<R;i++ )
	{
		for( j=0;j<C;j++ )
		{
			scanf("%c",map[i][j]);
			
			if( map[i][j] == 'S' ){
				Sr = i;
				Sc = j;
			}
			else if( map[i][j] == 'T' ){
				Tr = i;
				Tc = j;
			}
			
			Reachable[i][j]=0;
		}
	}
	
	return 0;
}

//return 0可以到达，1不能到达 
int DFStoT( int r, int c)
{
	if( map[r][c] == '#' ){
		return 1;
	}
	else if( map[r][c] == '+' || map[r][c] == 'S' || map[r][c] == 'T' ){
		
	}
}

/* AC CODE */
/* CCF201312-5 I’m stuck! */
 
#include <iostream>
#include <cstring>
 
using namespace std;
 
const int N = 50;
const int DIRECTSIZE = 4;
struct _direct {
    int dr, dc;
} direct[DIRECTSIZE] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
char grid[N][N+1];
int visited[N][N], visited2[N][N];
 
int R, C;
 
// 判断坐标是否合法或可移动到
inline bool islegal(int r, int c)
{
    if(0 <= r && r < R && 0 <= c && c < C && !visited[r][c] && grid[r][c] != '#')
        return true;
    else
        return false;
}
 
// 深度优先搜索
void dfs(int r, int c)
{
    int nextr, nextc;
 
    visited[r][c] = 1;
 
    if(grid[r][c] == '+' || grid[r][c] == 'S' || grid[r][c] == 'T') {
        for(int i=0; i<DIRECTSIZE; i++) {
            nextr = r + direct[i].dr;
            nextc = c + direct[i].dc;
 
            if(islegal(nextr, nextc))
                dfs(nextr, nextc);
        }
    } else if(grid[r][c] == '-') {
        for(int i=2; i<DIRECTSIZE; i++) {
            nextr = r + direct[i].dr;
            nextc = c + direct[i].dc;
 
            if(islegal(nextr, nextc))
                dfs(nextr, nextc);
        }
    } else if(grid[r][c] == '|') {
        for(int i=0; i<2; i++) {
            nextr = r + direct[i].dr;
            nextc = c + direct[i].dc;
 
            if(islegal(nextr, nextc))
                dfs(nextr, nextc);
        }
    } else if(grid[r][c] == '.') {
        nextr = r + direct[1].dr;
        nextc = c + direct[1].dc;
 
        if(islegal(nextr, nextc))
            dfs(nextr, nextc);
    }
}
 
int main()
{
    int sr, sc, tr, tc;
 
    // 输入数据
    cin >> R >> C;
    for(int i=0; i<R; i++)
        cin >> grid[i];
 
    // 找到起点和终点坐标
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(grid[i][j] == 'S')
                sr = i, sc = j;
            else if(grid[i][j] == 'T')
                tr = i, tc = j;
 
    // bfs：标记从"S"点可以到达的点
    memset(visited, 0, sizeof(visited));
    dfs(sr, sc);
    memcpy(visited2, visited, sizeof(visited));
 
    if(visited2[tr][tc]) {
        int count = 0;
 
        // 统计"S"点可以到达、而不可到达"T"点的数量
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++) {
                if(visited2[i][j]) {    // "S"点可以到达的<i,j>点
                    // bfs：标记从<i,j>点开始可以到达的点，如果不能到达"T"点则计数
                    memset(visited, 0, sizeof(visited));
                    dfs(i, j);
 
                    if(!visited[tr][tc])
                        count++;
                }
            }
 
        // 输出结果
        cout << count << endl;
    } else
        // 从"S"点不可以到达"T"点
        cout << "I'm stuck!" << endl;
 
    return 0;
}


