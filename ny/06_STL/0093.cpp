#define _CRT_SBCURE_NO_DEPRECATE
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	stack<int> s[4];
	int n;
	cin >> n;
	while(n--)
	{
		int p,q,f,t;
		cin >> p >> q;
		int flag = 0;

		while(!s[1].empty())
			s[1].pop();
		while(!s[2].empty())
			s[2].pop();
		while(!s[3].empty())
			s[3].pop();

		for(int i = p;i >= 1;i--)   // 初始化
			s[1].push(i);
		// for(int i = 1;i <= p;i++)
		// {
		// 	cout << s[1].top() << " ";
		// 	s[1].pop();
		// }
		for(int i = 1;i <= q;i++)
		{
			cin >> f >> t;
			if(s[f].empty())
			{
				flag = 1;
			}
			else
			{
				int temp = s[f].top();
				if(s[t].empty())
				{
					s[t].push(temp);
					s[f].pop();
				}
				else
				{
					if(s[t].top() > temp)
					{
						s[t].push(temp);
						s[f].pop();
					}
					else
					{
						flag = 1;
					}
				}
			}
		}
		if(flag)
			cout << "illegal" << endl;
		else
			cout << "legal" << endl;
	}
	return 0;
}


