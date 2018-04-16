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

const int INF = 0xffffff0;
int minV = INF;
int maxV = -INF;

// 一维数组存放线段树
struct Node   // 不要左右子节点指针的做法
{
	int L,R;
	int minV,maxV;
	int Mid()
	{
		return (L+R)/2;
	}
};
Node tree[800010];   // 4倍叶子节点的数量就够

void BuildTree(int root,int L,int R)
{
	tree[root].L = L;
	tree[root].R = R;
	tree[root].minV = INF;
	tree[root].maxV = -INF;
	if(L != R)
	{
		BuildTree(2*root+1,L,(L+R)/2);
		BuildTree(2*root+2,(L+R)/2+1,R);
	}
}

void Insert(int root,int i,int v)
{
	// 将第i个数，其值为v，插入线段树
	if(tree[root].L == tree[root].R)
	{
		// 成立时亦有tree[root].R == i
		tree[root].minV = tree[root].maxV = v;
		return ;
	}
	tree[root].minV = min(tree[root].minV,v);
	tree[root].maxV = max(tree[root].maxV,v);
	if(i <= tree[root].Mid())
		Insert(2*root+1,i,v);
	else
		Insert(2*root+2,i,v);
}

void Query(int root,int s,int e)
{
	// 查询区间[s,e]中的最大值和最小值，如果更优就记在全局变量
	// minV和maxV里
	if(tree[root].minV >= minV && tree[root].maxV <= maxV)
		return ;
	if(tree[root].L == s && tree[root].R == e)
	{
		minV = min(minV,tree[root].minV);
		maxV = max(maxV,tree[root].maxV);
		return ;
	}
	if(e <= tree[root].Mid())
		Query(2*root+1,s,e);
	else
		if(s > tree[root].Mid())
			Query(2*root+2,s,e);
		else
		{
			Query(2*root+1,s,tree[root].Mid());
			Query(2*root+2,tree[root].Mid()+1,e);
		}
}

int main()
{	
	int n,q,h;
	int i;
	scanf("%d %d",&n,&q);
	BuildTree(0,1,n);
	for(i = 1;i <= n;i++)
	{
		scanf("%d",&h);
		Insert(0,i,h);
	}
	for(i = 0;i < q;i++)
	{
		int s,e;
		scanf("%d %d",&s,&e);
		minV = INF;
		maxV = -INF;
		Query(0,s,e);
		printf("%d\n",maxV-minV);
	}
	return 0;
}


