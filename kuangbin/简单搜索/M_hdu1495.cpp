#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

char map[35][35][35];
int vis[35][35][35];

int k,n,m,sx,sy,sz,ex,ey,ez;
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct node
{
	int x,y,z,step;
};

int check(int x,int y,int z)
{
	if(x < 0 || y < 0 || z < 0 || x >= k || y >= n || z >= m || map[x][y][z] == '#' || vis[x][y][z])
		return 1;
	return 0;
}

int bfs()
{
	
}

int main()
{

	return 0;
}