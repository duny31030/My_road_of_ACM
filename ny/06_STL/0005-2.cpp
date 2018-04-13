// STL写法
#define _CRT_SBCURE_NO_DEPRECATE

#include <string>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>

using namespace std;


// find(t,x)   从x位置开始向后查找串t，返回第一次找到该串的位置，然后返回，否则返回npos


int main()
{
	int t,ans;
	scanf("%d",&t);
	while(t--)
	{
        string p,t;
		int num = 0;
		cin >> p >> t;
		ans = t.find(p);
		while(ans != string::npos)
		{
			num++;
			ans = t.find(p,ans+1);
		}
		cout << num << endl;
	}
	
	return 0;
}


