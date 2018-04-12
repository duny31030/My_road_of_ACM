#include <stdio.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)&& n)
	{
		switch(n)
		{
			case 1:	printf("1\n");	break;
			case 2:	printf("0\n");	break;
			case 3:	printf("0\n");	break;
			case 4:	printf("2\n");	break;
			case 5:	printf("10\n");	break;
			case 6:	printf("4\n");	break;
			case 7:	printf("40\n");	break;
			case 8:	printf("92\n");	break;
			case 9:	printf("352\n");	break;
			case 10:	printf("724\n");	break;
		}
	}
	return 0;
}