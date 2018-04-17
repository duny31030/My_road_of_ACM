#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
#define INF  0xffffff0
// len：输入的数字的位数
// e:要删除的最少位
int len,i,j,k,e;
// c[]：用字符串来存储数字,方便取每一位数
char c[100];

// x : 第x位   val : 当前的值   step : 
void dfs(int x,int val,int step)
{
	int b = c[x]-'0';   // 取c[x]本来对应的数字的值

	if(x == len-1)   // 取到了字符串c[]最后一位
	{
		// val不要c[x]位
		int c = sqrt(val);
		if(c*c == val && val != 0)
		{
			e = min(step+1,e);
		}
		// val要c[x]位
		val = val*10+b;
		c = sqrt(val);
		if(c*c == val && val != 0)
		{
			e = min(step,e);
		}
		return ;
	}

	if(b != 0 || val != 0)
	{
		dfs(x+1,val*10+b,step);
	}
	dfs(x+1,val,step+1);
}


int main()
{
	cin >> c;
	len = strlen(c);
	e = INF;
	dfs(0,0,0);
	if(e != INF)
	{
		cout << e << endl;
	}
	else
		cout << "-1" << endl;
	return 0;
}


