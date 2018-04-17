// 未加懒标记，TLE待补
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 100005
#define INF 0x7fffffff

int num[N];
struct node 
{
	int l,r;
	int sum;
	int mid()
	{
		return (l+r)/2;
	}
}tree[N*4];

void BuildTree(int root,int l,int r)
{
	tree[root].l = l;
	tree[root].r = r;
	if(l == r)
	{
		tree[root].sum = num[l];
		return ;
	}
	BuildTree(root*2,l,(l+r)/2);
	BuildTree(root*2+1,(l+r)/2+1,r);
	tree[root].sum = tree[root*2].sum+tree[root*2+1].sum;
}

void add(int root,int i,int t)
{
	tree[root].sum += t;
	if(tree[root].l == i && tree[root].r == i)
		return ;
	if(i <= tree[root].mid())
		add(root*2,i,t);
	else
		add(root*2+1,i,t);
}

int query(int root,int s,int e)
{	
	if(tree[root].l == s && tree[root].r == e)
		return tree[root].sum;
	if(e <= tree[root].mid())
		return query(root*2,s,e);
	else
		if(s > tree[root].mid())
			return query(root*2+1,s,e);
		else
			return query(root*2,s,tree[root].mid())+query(root*2+1,tree[root].mid()+1,e);

}

int main()
{
	int n,m,i,tmp,x,y,k,j;
	scanf("%d %d",&n,&m);
	for(i = 1;i <= n;i++)
		scanf("%d",&num[i]);
	BuildTree(1,1,n);
	for(i = 1;i <= m;i++)
	{
		scanf("%d %d %d",&tmp,&x,&y);
		if(tmp == 1)
		{
			scanf("%d",&k);
			for(j = x;j <= y;j++)
			{
				add(1,j,k);
			}
		}
		else
		{
			printf("%d\n",query(1,x,y));
		}
	}

	return 0;
}

