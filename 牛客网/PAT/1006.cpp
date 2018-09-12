#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    int da=0,db=0,pa=0,pb=0;
    char a[20],b[20];
    int na,nb;
    scanf("%s %d %s %d",a,&da,b,&db);
    na=strlen(a);
    nb=strlen(b);
    for(int i=0;i<na;i++)
    {
        if(da == (int)(a[i]-'0'))
            pa++;
    }
    for(int j=0;j<nb;j++)
    {
        if(db == (int)(b[j]-'0'))
            pb++;
    }
    int suma=0,sumb=0;
    for(int i=1;i<=pa;i++)
    {
        suma=suma*10+da;
    }
    for(int j=1;j<=pb;j++)
    {
        sumb=sumb*10+db;
    }
    printf("%d\n",suma+sumb);

    return 0;
}
