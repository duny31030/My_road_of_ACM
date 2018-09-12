#define _CRT_SBCURE_NO_DEPRECATE
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;



int main()
{

	int n;
	scanf("%d",&n);
	getchar();
	
	for(int j = 1;j <= n;j++)
	{
		// char s[110];
		// gets(s);
		// getchar();
		int a = 0,e = 0,ii = 0,o = 0,u = 0;
		// int len = strlen(s);
		// cout << len << endl;

		char xx;
		while(scanf("%c",&xx)!=EOF && (xx != '\n'))
		{
			// for(int i = 0;i < len;i++)
			// {
				if(xx == 'a')
					a++;
				if(xx == 'e')
					e++;
				if(xx == 'i')
					ii++;
				if(xx == 'o')
					o++;
				if(xx == 'u')
					u++;
			// }
		}


		
		printf("a:%d\n",a);
		printf("e:%d\n",e);
		printf("i:%d\n",ii);
		printf("o:%d\n",o);
		printf("u:%d\n",u);
		if(j != n)
			printf("\n");
	}
	return 0;
}


