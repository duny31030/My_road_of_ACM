#include <bits/stdc++.h>

using namespace std;

double MAX = 0.0;   // 存储答案
int a[5] = {0,1,2,3,5};   // 存的年数
double b[5];   // 年利率

// n:还可以存入n年   temp:目前的这种方案可获得的收益
void dfs(int n,double temp)
{
	// 当不能再存入时进行比较，是否当前方案比之前的方案收益更大
	// 若比之前的方案收益更大则更新MAX的值
	if(n == 0)
	{
		if(MAX < temp)
		{
			// 更新MAX的值
			MAX = temp;
			return ;
		}
	}
	else
	{
		for(int i = 4;i >= 1;i--)
		{
			// 如果n-a[i] >= 0说明可以进行年数为a[i]的存款行为
			if((n-a[i]) >= 0)
			{
				temp *= pow(1.0+b[i],a[i]);
				dfs(n-a[i],temp);   // 尝试继续存入
				// 尝试结束，回到尝试前的状态
				temp /= pow(1.0+b[i],a[i]);
			}
		}
	}
	return ;
}

int main()
{
	int n;	
	scanf("%d",&n);   // 读入存的总年数n
	// 读入1、2、3、5年的年利率
	scanf("%lf %lf %lf %lf",&b[1],&b[2],&b[3],&b[4]);
	// 暴力搜索
	dfs(n,1.0);
	// 输出
	printf("%.5f\n",MAX);
	return 0;
}
