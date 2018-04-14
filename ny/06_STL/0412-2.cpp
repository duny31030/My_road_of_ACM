#define _CRT_SBCURE_NO_DEPRECATE
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bitset<32> b(n);
		int i,coun = 0;
		for(i = 0;i < 32;i++)
		{
			if(b[i] == 1)
				coun++;
			if(b[i] == 1 && b[i+1] == 0)
			{
				b[i] = 0;
				b[i+1] = 1;
				break;
			}
		}
		int j = i-1;
		for(int i = 0;i <= j;i++)
		{
			if(i < coun-1)
				b[i] = 1;
			else
				b[i] = 0;
		}
		cout << b.to_ulong() << endl;
	}

	
	return 0;
}


