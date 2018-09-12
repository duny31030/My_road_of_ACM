#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    char s[2000];
    
    scanf("%s",s);
    int a[10]={0};
    int n=strlen(s);
    //printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        //printf("%d\n",i);
        int tmp=0;
        tmp=(int)(s[i]-'0');
        //printf("%d\n",tmp);
        a[tmp]++;
    }
    for(int i=0;i<=9;i++)
    {
        if(a[i] != 0)
        {
            printf("%d:%d\n",i,a[i]);
        }
    }

    return 0;
}
