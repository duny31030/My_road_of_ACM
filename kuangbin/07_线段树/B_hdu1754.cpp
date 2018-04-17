// https://blog.csdn.net/panyanyany/article/details/6776300
#define _CRT_SBCURE_NO_DEPRECATE
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 200010;
// const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;

int num[N];
struct node
{
	int l,r;
	int mmax;
	int mid()
	{
		return (l+r)/2;
	}
}tree[N*4];

int BuildTree(int root,int l,int r)
{
	tree[root].l = l;
	tree[root].r = r;
	
	if(l == r)
	{
		return tree[root].mmax = num[l];
	}
	int a,b;
	a = BuildTree(root*2,l,(l+r)/2);
	b = BuildTree(root*2+1,(l+r)/2+1,r);

	return tree[root].mmax = max(a,b);
}

// void add(int root,int i,int t)
// {
// 	// tree[root].sum += t;
// 	if(tree[root].l == i && tree[root].r == i)
// 		return ;
// 	if(i <= tree[root].mid())
// 		add(root*2,i,t);
// 	else
// 		add(root*2+1,i,t);
// }

int find(int root,int l,int r)
{
	if(tree[root].l > r || tree[root].r < l)
		return 0;
	if(l <= tree[root].l && tree[root].r <= r)
		return tree[root].mmax;
	int a,b;
	a = find(root*2,l,r);
	b = find(root*2+1,l,r);
	return max(a,b);
}

int update(int root,int pos,int val)
{
	if(pos < tree[root].l || tree[root].r < pos)
		return tree[root].mmax;

	if(tree[root].l == pos && tree[root].r == pos)
		return tree[root].mmax = val;
	int a,b;
	a = update(root*2,pos,val);
	b = update(root*2+1,pos,val);

	tree[root].mmax = max(a,b);

	return tree[root].mmax;
}


// int query(int root,int s,int e)
// {
// 	if(tree[root].l == s && tree[root].r == e)
// 		return tree[root].mmax;
// 	if(e <= tree[root].mid())
// 		return query(root*2,s,e);
// 	else
// 		if(s > tree[root].mid())
// 			return query(root*2+1,s,e);
// 		else
// 			return max(query(root*2,s,tree[root].mid()),query(root*2+1,tree[root].mid()+1,e));
// }

int main()
{
	int n,m,i,j,a,b;
	char s;
	scanf("%d %d",&n,&m);
	for(i = 1;i <= n;i++)
		scanf("%d",&num[i]);
	BuildTree(1,1,n);
	for(i = 1;i <= m;i++)
	{
		getchar();
		scanf("%c",&s);
		if(s == 'Q')
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",find(1,a,b));
		}
		if(s == 'U')
		{
			scanf("%d %d",&a,&b);
			update(1,a,b);
		}
	}
	return 0;
}


