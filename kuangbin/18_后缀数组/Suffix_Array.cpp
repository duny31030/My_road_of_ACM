#include <bits/stdc++.h>

using namespace std;

const int maxn = 2510;

/*
*Suffix Array
*倍增算法   O(nlog(n))
*待排序数组长度为n,放在0~n-1中,最后面补一个0
*build_sa( ,n+1, );   // 注意是n+1;
*getHeight( ,n);
*例如:
*n = 8;
*num[] 	  = {1,1,2,1,1,1,1,2,0};   // 注意num最后一位为0,其他大于0   
*rank[]   = {4,6,8,1,2,3,5,7,0};   // rank[0~n-1]为有效值,rank[n]必定为0
*sa[] 	  = {8,3,4,5,0,6,1,7,2};   // sa[1~n]为有效值,sa[0]必定为n是无效值
*height[] = {0,0,3,2,3,1,2,0,1};   // height[2~n]为有效值
*/

int sa[maxn];   // SA数组,表示将S的n个后缀从小到大排序后把拍好序的
				// 后缀的开头位置顺次放入SA中
int t1[maxn],t2[maxn],c[maxn];   // 求SA数组需要的中间变量,不需要赋值
int rank[maxn],height[maxn];
// 待排序的字符串放在s数组中,从s[0]到s[n-1],长度为n,且最大值小于m,
// 除s[n-1]外的所有s[i]都大于0,r[n-1] = 0
// 函数结束以后结果放在sa数组中

void build_sa(int s[],int n,int m)
{
	int i,j,p,*x = t1,*y = t2;
	// 第一轮基数排序,如果s的最大值很大,可改为快速排序
	for(i = 0;i < m;i++)	c[i] = 0;
	for(i = 0;i < n;i++)	c[x[i] = s[i]]++;
	for(i = 1;i < m;i++)	c[i] += c[i-1];
	for(i = n-1;i >= 0;i--)	sa[--c[x[i]]] = i;
}






// int waa[maxn],wbb[maxn],wvv[maxn],wss[maxn];
// int cmp(int *r,int a,int b,int l)
// {
// 	return r[a] == r[b] && r[a+1] == r[b+1];
// }

// void da(int *r,int *sa,int n,int m)
// {
// 	int i,j,p,*x = waa,*y = wbb,*t;
// 	// 第一轮基数排序
// 	for(i = 0;i < m;i++)	wss[i] = 0;
// 	for(i = 0;i < n;i++)	wss[x[i] = r[i]]++;
// 	for(i = 1;i < m;i++)	wss[i] += wss[i-1];
// 	for(i = n-1;i >= 0;i--)	sa[--wss[x[i]]] = i;
// 	for(j = 1,p = 1;p < n;j *= 2,m = p)
// 	{
// 		for(p = 0,i = n-j;i<n;i++)	y[p++] = i;
// 		for(i = 0;i < n;i++)	if(sa[i] >= j)	y[p++] = sa[i]-j;
// 		for(i = 0;i < n;i++)	wvv[i] = x[y[i]];
// 		for(i = 0;i < m;i++)	wss[i] = 0;
// 		for(i = 0;i < n;i++)	wss[wvv[i]]++;
// 		for(i = 1;i < m;i++)	wss[i] += wss[i-1];
// 		for(i = n-1;i >= 0;i--)	sa[--wss[wvv[i]]] = y[i];
// 		for(t = x,x = y,y = t,p = 1,x[sa[0]] = 0,i = 1;i < n;i++)
// 			x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
// 	}
// 	return ;
// }

int r[maxn];
char str[maxn];

int main()
{
	while(scanf("%s",str) == 1)
	{
		int len = strlen(str);
		int n = 2*len+1;
		for(int i = 0;i < len;i++)
			r[i] = str[i];
		r[n] = 1;   // 这个和其他的都应该不同
		for(int i = 0;i < len;i++)
			r[i+len+1] = str[len-1-i];
		r[n] = 0;

	}
	
	return 0;
}


