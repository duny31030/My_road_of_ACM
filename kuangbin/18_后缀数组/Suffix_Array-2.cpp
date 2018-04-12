// https://blog.csdn.net/YxuanwKeith/article/details/50636898

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

// 变量的含义		:
// Str 			: 需要处理的字符串(长度为len)
// Suffix[i] 	: Str下标为i~len的连续子串(即后缀)
// Rank[i] 		: Suffix[i]在所有后缀中的排名
// SA[i] 		: 满足Suffix[SA[1]] < Suffix[SA[2]] < ··· < Sufffix[SA[len]],即
//				  排名为i的后缀为Suffix[SA[i]](与Rank是互逆运算)
// Height[i]	: 表示Suffix[SA[i]]和Suffix[SA[i-1]]的最长公共前缀,排名相邻的两个后缀
//				  的最长公共前缀
// H[i]			: 等于Height[Rank[i]],也就是后缀Suffix[i]和它前一名的后缀的最长公共前缀

char ch[MAXN],All[MAXN];
int SA[MAXN],Rank[MAXN],Height[MAXN],tax[MAXN],tp[MAXN],a[MAXN],n,m;
// Rank[i] 	  第i个后缀的排名;
// SA[i]	  排名为i的后缀位置;
// Height[i]  排名为i的后缀与排名为(i-1)的后缀的LCP
// a为原串
char str[MAXN];

void RSort()
{
	// Rank为第一关键字,tp为第二关键字
	for(int i = 0;i <= m;i++)	tax[i] = 0;
	for(int i = 1;i <= n;i++)	tax[Rank[tp[i]]]++;
	for(int i = 1;i <= m;i++)	tax[i] += tax[i-1];
	for(int i = n;i >= 1;i--)	SA[tax[Rank[tp[i]]]--] = tp[i]; 	// 确保满足第一关键字的同时
																	// 再满足第二关键字的要求
}   // 基数排序,把新的二元组排序

// 通过二元组两个下标的比较确定两个子串是否相同
int cmp(int *f,int x,int y,int w)
{
	return f[x] == f[y] && f[x+w] == f[y+w];
}

void Suffix()
{
	// SA
	for(int i = 1;i <= n;i++)
		Rank[i] = a[i],tp[i] = i;
	m = 127,RSort();   // 一开始是以单个字符为单位,所以(m = 127)


	for(int w = 1,p = 1,i;p < n;w += w,m = p)   // 把子串长度翻倍,更新Rank
	{
		// w	当前一个子串的长度
		// m 	当前离散后的排名种类数
		// 当前tp(第二关键字)可直接由上一次的SA的得到
		for(p = 0,i = n-w+1;i <= n;i++)	tp[++p] = i;   // 长度越界,第二关键字为0
		for(i = 1;i <= n;i++)
			if(SA[i] > w)
				tp[++p] = SA[i]-w;

		// 更新SA值,并用tp暂时存下上一轮的rank(用cmp比较)
		RSort(),swap(Rank,tp),Rank[SA[1]] = P = 1;

		// 用已经完成的SA来更新与它互逆的rank,并离散rank
		for()
	}

}



int main()
{

	
	return 0;
}


