#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int INF = 65535;

int c[6][6] = {
				{0,0,0,0,0,0},
				{0,0,10,INF,30,100},
				{0,INF,0,50,INF,INF},
				{0,INF,INF,0,INF,10},
				{0,INF,INF,20,0,60},
				{0,INF,INF,INF,INF,0}
				};
bool vis[6];

void Dijkstra(int n,int v,int dist[],int prev[])
{
	for(int i = 1;i <= n;i++)
	{
		dist[i] = c[v][i];   // 首先对dist数组初始化
		vis[i] = false;   // 将vis数组置空
		if(dist[i] == INF)    // 判断v->i是否可以到达   
			prev[i] = 0;
		else   // 如果可以到达，给prev赋值
			prev[i] = v;
	}
	dist[v] = 0;
	vis[v] = true;  
	for(int i = 1;i <= n;i++)
	{
		int temp = INF;
		int u = v;
		for(int j = 1;j <= n;j++)
		{
			if((!vis[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		vis[u] = true;
		for(int j = 1;j <= n;j++)
		{
			if((!vis[j]) && (c[u][j] < INF))
			{
				int newdist = dist[u]+c[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
		// for(int k = 1;k <= n;k++)
		// 	cout << dist[k] << " ";
		// cout << endl;
	}
}

void find(int m,int prev[])
{
	int prevNode = prev[m];
	vector<int> vec;
	vec.push_back(m);
	vec.push_back(prevNode);
	while(prevNode != 1)
	{
		prevNode = prev[prevNode];
		vec.push_back(prevNode);
	}
	cout << "最短路径：" << endl;
	for(int i = vec.size()-1;i >= 0;i--)
		cout << vec[i] << " ";
	cout << endl;
}


int main()
{
	int m;
	int dist[6];
	int prev[6];

	Dijkstra(5,1,dist,prev);
	// 默认起点为1
	cout << "请输入终点：" << endl;
	cin >> m;
	find(m,prev);
	return 0;
}


