#include <bits/stdc++.h>

using namespace std;

int queen[10];
int n;
bool check(int n,int i)
{
	for(int k = 1;k < n;k++)
	{
		if(queen[k] == i)
			return false;
		if(queen[k]-i == n-k || queen[k]-i == k-n)
			return false;
	}
	return true;
}

void print()
{
	for(int i = 1;i <= n;i++)
		cout << queen[i] << " ";
	cout << endl; 
}

void n_queen(int step)
{
	if(step == n+1)
	{
		print();
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(check(step,i))
		{
			queen[step] = i;
			n_queen(step+1);
			queen[step] = 0;
		}
	}
	return ;
}

int main()
{
	cout << "请输入皇后数量:" << endl;
	cin >> n;
	n_queen(1);
	return 0;
}


