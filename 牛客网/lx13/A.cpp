#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	char s[60];
	scanf("%s",s);
	int len = strlen(s);
	int fo = 0,se = 0,li1 = 0,li2 = 0;
	for(int i = 0; i < len;i++)
	{
		if(s[i] == '4')
			fo++;
		if(s[i] == '7')
			se++;
		if(s[i] == '4' && s[i+1] == '7')
			li1++;
		if(s[i] == '7' && s[i+1] == '4')
			li2++;
	}
	if(fo != se)
	{
		if(fo > se)
			printf("4\n");
		else
			printf("7\n");
	}
	else
	{
		if(fo == 0 && se == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("4\n");
		
		}
	}
	return 0;
}