#include <cstdio>

using namespace std;

int main()
{
    double start=0.0,end=0.0;
    scanf("%lf %lf",&start,&end);
    end = (end-start)/100;
    long long s;
    s=(int)(end+0.5);
    int ss=0,mm=0,hh=0;
    ss=s%3600%60;
    hh=s/3600;
    mm=s%3600/60;
    if(hh<10)   printf("0%d:",hh);  else    printf("%d:",hh);
    if(mm<10)   printf("0%d:",mm);  else    printf("%d:",mm);
    if(ss<10)   printf("0%d\n",ss); else    printf("%d\n",ss);
    return 0;
}

