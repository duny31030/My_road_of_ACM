//不懂

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 100001;

bool vis[maxn];   // 标记数组
int step[maxn];   // 标记到了每一位置所走的步数
queue <int> q;   // 定义队列

int bfs(int n,int k)
{
	int head,next;
	q.push(n);   // n入队
	step[n] = 0;
	vis[n] = true;   // 标记已访问
	while(!q.empty())   // 当前队列非空
	{
		head = q.front();
		q.pop();
		for(int i = 0;i < 3;i++)
		{
			if(i == 0)
				next = head+1;
			else if(i == 1)
				next = head+1;
			else
				next = head*2;

			if(next < 0 || next >= maxn)   // 排除出界情况
				continue;

			if(!vis[next])   // 如果next位置未被访问
			{
				q.push(next);   // 入队
				step[next] = step[head]+1;   // 步数+1
				vis[next] = true;   // 标记已访问
			}
			if(next == k)
				return step[next];   // 当遍历到结果，返回步数
		}
	}
	return 0;
}

int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		memset(step,0,sizeof(step));
		memset(vis,false,sizeof(vis));

		while(!q.empty())   // 注意调用前要清空
			q.pop();
		if(n >= k)
			printf("%d\n",n-k);
		else
			printf("%d\n",bfs(n,k));
	}
	return 0;
}