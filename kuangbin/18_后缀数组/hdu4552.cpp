#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

const int MAXN = 100010;

int sa[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];
int rank[MAXN],height[MAXN];

void build_sa(int s[],int n,int m)
{
	int i,j,p,*x = t1,*y = t2;
	// 第一轮基数排序
	for(i = 0;i < m;i++)	c[i] = 0;
	for(i = 0;i < n;i++)	c[x[i] = s[i]]++;
	for(i = 1;i < m;i++)	c[i] += c[i-1];
	for(i = n-1;i >= 0;i--)	sa[--c[x[i]]] = i;

	for(j = 1;j <= n;j <<= 1)   // 倍增
	{
		p = 0;
		// 直接利用sa数组排序第二关键字
		for(i = n-j;i < n;i++)	y[p++] = i;   // 后面的j个数第二关键字为空的最小
	}
}










char str[MAXN];
int s[MAXN];

int main()
{
	while(~scanf("%s",str))
	{
		int n = strlen(str);
		for(int i = 0;i < n;i++)	s[i] = str[i];
		build_sa(s,n+1,128);
	}
	

	return 0;
}