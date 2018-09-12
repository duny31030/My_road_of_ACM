// AC
#define _CRT_SBCURE_NO_DEPRECATE
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	map<string,int> m;
	int n;
	string temp;
	scanf("%d",&n);
	while(n--)
	{
		cin >> temp;
		if(m[temp]  == 0)
		{
			m[temp]++;
			cout << "OK" << endl;
		}
		else
		{
			cout << temp << m[temp] << endl;
			m[temp]++;
		}
	}

	
	return 0;
}


