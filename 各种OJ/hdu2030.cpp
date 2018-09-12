#include<stdio.h>
#include<string.h>

int main()
{
	char a[100001];
	int n;
	int i;
	int s;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
       gets(a);
	   s=0;
	   for(i=0;i<strlen(a);i++)
	   {
		   if(a[i]<0)
			 s++;
	   }
	   printf("%d\n",s/2);
	}
	return 0;
}