#include <cstdio>
#include <cstring>

using namespace std;

struct People
{
    char name[20];
    int year,month,day;
}peo[10005];




int com(int x,int i)
{
    if(peo[x].year*365+peo[x].month*30+peo[x].day < peo[i].year*365+peo[i].month*30+peo[i].day)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    char maxs[20],mins[20];
    int ma,mi;
    scanf("%d",&t);
    int ii=0;
    for(int i=1;i<=t;i++)    
    {
        scanf("%s %d/%d/%d",peo[i].name,&peo[i].year,&peo[i].month,&peo[i].day);
        if(peo[i].year*365+peo[i].month*30+peo[i].day > 735386)
        {
            t--;
            continue;
        }
            //continue;

        if(peo[i].year*365+peo[i].month*30+peo[i].day < 662386)
        {
            t--;
            continue;
        }
            //continue;
       

        if(ii == 0)
        {
            ii++;
            strcpy(maxs,peo[i].name);
            printf("%s\n",maxs);
            ma=i;
            mi=i;            
            strcpy(mins,peo[i].name);
        }
        else
        {
            if(!com(ma,i))
            {
                strcpy(maxs,peo[i].name);
                ma=i;
            }

            if(com(mi,i))
            {
                strcpy(mins,peo[i].name);
                mi=i;
            }
        }
    }
    printf("%d %s %s\n",t,maxs,mins);
    return 0;
}
