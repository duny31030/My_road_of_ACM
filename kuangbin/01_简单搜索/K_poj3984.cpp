#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	int x,y; 
	int f;   // 父节点在队列中的下标
}que[100];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int tail = 0,head = 0;   // 设置队头和队尾
int vis[5][5];   // 标记数组
int a[5][5];
void bfs(int startx,int starty,int endx,int endy)
{	
	que[0].x = startx,que[0].y = starty,que[0].f = -1;   // 将初始结点[0,0]压入队列
	tail++;
	vis[startx][starty] = 1;
	while(head < tail)   // 若队列不为空
	{
		for(int i = 0;i < 4;i++)   // 四个方向搜索可达方向
		{
			int tx = que[head].x+dx[i];
			int ty = que[head].y+dy[i];
			if(tx < 0 || tx > 5 || ty < 0 || ty > 5 | a[tx][ty] == 1 || vis[tx][ty] == 1)
				continue;

			que[tail].x = tx;
			que[tail].y = ty;
			que[tail].f = head;
			tail++;
			vis[tx][ty] = 1;
			if(endx == tx && endy == ty)
				return ;
		}
		head++;   // 出队
	}
	
}

void print(node now)
{
	if(now.f == -1)
	{
		printf("(%d, %d)\n",now.x,now.y);
	}
	else
	{
		print(que[now.f]);
		printf("(%d, %d)\n",now.x,now.y);
	}
}


int main()
{
	int i,j;
	for(i = 0;i < 5;i++)
		for(j = 0;j < 5;j++)
			scanf("%d",&a[i][j]);

	bfs(0,0,4,4);
	// cout << "end!" << endl;
	print(que[tail-1]);
	return 0;
}


