// 暴力 超时了
#define _CRT_SBCURE_NO_DEPRECATE
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bitset<32> b(n);
		int nlen = b.count();
		int ilen;
		for(int i = n+1;;i++)
		{
			bitset<32> bb(i);
			ilen = bb.count();
			if(nlen == ilen)
			{
				cout << i << endl;
				break;
			}
		}	
	}
	
	return 0;
}


