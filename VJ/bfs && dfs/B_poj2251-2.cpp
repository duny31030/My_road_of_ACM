#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

int vis[35][35][35];
char Dungeon[35][35][35];
int mmin;

int l,r,c,i,j,k,sx,sy,sz,ex,ey,ez;

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct node
{
	int z;   // 层
	int x;   // 横坐标
	int y;   // 纵坐标
	int s;   // 步数
}que[3000];

bool check(int x,int y,int z)
{
	if(x < 0 || y < 0 || z < 0 || x >= l || y >= r || z >= c || Dungeon[x][y][z] == '#' || vis[x][y][z])
		return true;
	return false;
}


int bfs()
{
	struct node a,next;
	queue<node> Q;
	a.x = sx;
	a.y = sy;
	a.z = sz;
	a.s = 0;
	vis[sx][sy][sz] = 1;
	Q.push(a);
	while(!Q.empty())
	{
		a = Q.front();
		Q.pop();
		if(a.x == ex && a.y == ey && a.z == ez)
			return a.s;
		for(int i = 0;i < 6;i++)
		{
			next = a;
			next.x = a.x+dx[i];
			next.y = a.y+dy[i];
			next.z = a.z+dz[i];
			if(check(next.x,next.y,next.z))
				continue;
			vis[next.x][next.y][next.z] = 1;
			next.s = a.s+1;
			Q.push(next);
		}
	}
	return 0;
}






int main()
{
	int head,tail;
	while(scanf("%d %d %d",&l,&r,&c)!=EOF)
	{
		if(l == 0 && r == 0 && c == 0)
			break;
		// 初始化数组
		memset(Dungeon,0,sizeof Dungeon);
		memset(vis,0,sizeof vis);
		mmin = 0;
		// 初始化队列
		head = 1;
		tail = 1;
		// 输入
		for(i = 0;i < l;i++)
			for(j = 0;j < r;j++)
				{
					scanf("%s",Dungeon[i][j]);
					for(k = 0;k < c;k++)
					{
						if(Dungeon[i][j][k] == 'S')
						{
							sx = i;	sy = j;	sz = k;
						}
						if(Dungeon[i][j][k] == 'E')
						{
							ex = i;	ey = j;	ez = k;
						}
					}
				}

		
		int ans;
		ans = bfs();
		if(ans)
			printf("Escaped in %d minute(s).\n",ans);
		else
			printf("Trapped!\n");

	}
	
	return 0;
}


