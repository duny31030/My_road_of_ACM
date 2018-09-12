#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
const int INF = 0xffffff0;

char s[100];
int len,flag;   // len记录s长度,flag做标记

void dfs(int x,int val,int step)
{
	int b = s[x]-'0';
	if(x == len-1)   // 搜索到最后一位
	{
		int c = sqrt(val);
		if(c*c == val && val != 0)  //此时先不取用c[x]
		{
			flag = min(flag,step+1);   // 因为不取用c[x]，所以相当于多删除了一个
		}
		val = val*10+b;   // 取用c[x]
		c = sqrt(val);
		if(c*c == val && val != 0)
		{
			flag = min(flag,step);
		}
		return ;
	}

	if(val != 0 || b != 0)
	{
		dfs(x+1,val*10+b,step);
	}
	// if(b == 0 && val == 0)
	dfs(x+1,val,step+1);   // 此时写为dfs(x+1,val*10+b,step+1) 
	                       // 或者 dfs(x+1,val*10,step+1)是没有区别的
};

int main()
{
	cin >> s;
	len = strlen(s);
	flag = INF;
	dfs(0,0,0);
	if(flag == INF)   // flag的值没有被更新，即没找到平方数
		cout << "-1" << endl;
	else
		cout << flag << endl;
	return 0;
}


