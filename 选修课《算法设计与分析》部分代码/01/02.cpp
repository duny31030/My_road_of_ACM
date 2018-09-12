#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
	char s[7];
	scanf("%s",s);
	int len = strlen(s);
	// printf("len = %d\n",len);
	long long out = 0;
	for(int i = 0;i < len;i++)
	{
		// printf(" %d = %d\n",i,s[i]-'a'+1);
		if(i == 0)
			out += (s[i]-'a'-i+1);
		else
		{
			out *= 26-i+1;
			// printf("out = %d\n",out);
			out += (s[i]-'a'-i+1);
		}
	}
	printf("%lld\n",out);
	return 0;
}