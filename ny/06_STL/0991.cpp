// WA 好像读错题了  应该用map
#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;



int main()
{
	int n;
	set<string> s;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		string temp;
		cin >> temp;
		if(s.find(temp) == s.end())
		{
			s.insert(temp);
			cout << "OK" << endl;
		}
		else
		{
			set<string>::iterator it;
			int ans = 1;
			for(it = s.begin();it != s.end();it++)
			{
				if(*it != temp)
					ans++;
				else
				{
					cout << *it << ans << endl;
					continue;
				}
			}

		}
	}
	return 0;
}


