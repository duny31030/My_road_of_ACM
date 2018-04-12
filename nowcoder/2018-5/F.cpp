#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;


int main()
{
	char s[13];
	scanf("%s",s);
	int a[13];
	int i=0;
	int length;
	while(s[i] != '\0')
	{
		a[i] = (int)(s[i] - '0');
		// printf("a[%d] = %d\n",i,a[i]);
		i++;

	}

	length = i;
	// printf("length = %d\n",length);
	// int iii=1;
	while(length != 1)
	{	
		int tmp = 0,cnt = 0;
		// printf("tmp = %d cnt = %d length = %d\n",tmp,cnt,length);
		for(i = 0;i < length;i++)
		{
			tmp += a[i];
			 // printf("tmp = %d\n",tmp);
			if(tmp >= 10)
			{
				 // printf("i = %d tmp = %d\n",i,tmp);
				a[cnt] = tmp%10;
				tmp = tmp/10;
				cnt++;
			}
			if(i == length - 1)
			{
				a[cnt] = tmp;
				cnt++;
			}
		}
		length = cnt;	
		// iii++;
	}
	printf("%d\n",a[0]);
		return 0;
}