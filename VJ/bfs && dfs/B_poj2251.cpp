#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}

int vis[35][35][35];
char Dungeon[35][35][35];
int mmin;

//    北
//  西  东
//    南
int run[4][2] = {
					{1,0},   // 向东
					{0,1},   // 向南
					{-1,0},  // 向西
					{0,-1}   // 向北
				};


void dfs(int sz,int sx,int sy,int step,int z,int x,int y)
{
	//判断是否到达出口
	if(Dungeon[sz][sx][sy] == 'E')
	{
		mmin = step;
		return ;
	}
	//向东南西北尝试
	for(int i = 0;i < 4;i++)
	{
		int tx,ty;
		tx = sx+run[i][0];
		ty = sy+run[i][1];
		// 判断是否可行
		if(tx >= 0 && tx < x && ty >= 0 && ty < y)
		{
			if(Dungeon[sz][tx][ty] == '.' && vis[sz][tx][ty] != 1)  // 可行
			{
				vis[sz][tx][ty] = 1;
				dfs(sz,tx,ty,step+1,z,x,y);
				// vis[sz][tx][ty] = 0;
			}
		}
	}
	int tz;
	tz = sz+1;
	if(tz >= 0 && tz < z)
	{
		if(Dungeon[tz][sx][sy] == '.' && vis[tz][sx][sy] != 1)   // 可行
		{
			vis[tz][sx][sy] = 1;
			dfs(tz,sx,sy,step+1,z,x,y);
		}
	}
	tz = sz-1;
	if(tz >= 0 && tz < z)
	{
		if(Dungeon[tz][sx][sy] == '.' && vis[tz][sx][sy] != 1)
		{
			vis[tz][sx][sy] = 1;
			dfs(tz,sx,sy,step+1,z,x,y);
		}
	}
}

int main()
{
	int l,r,c,i,j,k,sx,sy,sz;
	while(scanf("%d %d %d",&l,&r,&c)!=EOF)
	{
		if(l == 0 && r == 0 && c == 0)
			break;
		// 初始化数组
		memset(Dungeon,0,sizeof Dungeon);
		memset(vis,0,sizeof vis);
		mmin = 0;
		// 输入
		for(i = 0;i < l;i++)
			for(j = 0;j < r;j++)
				{
					scanf("%s",Dungeon[i][j]);
					// 记录起点
					// if(Dungeon[i][j][k] == 'S')
					// {
					// 	sx = j;	sy = k;	sz = i;
					// }
				}

		dfs(0,0,0,0,l,r,c);

		if(mmin)
			printf("%d\n",mmin);
		else
			printf("Trapped!\n");
	}
	
	return 0;
}


