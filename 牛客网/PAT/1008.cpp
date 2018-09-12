#include <cstdio>

using namespace std;

int main()
{
    char a[110]={'0'};
    char b[110]={'0'};
    int win=0,lose=0,tie=0;
    int n;
    int ca[4]={0};
    int cb[4]={0};
    scanf("%d",&n);
    getchar(); 
    for(int i=1;i<=n;i++) 
    { 
       // printf("i=%d\n",i); 
        scanf("%c %c",&a[i],&b[i]); 
       // printf("a[%d]=%c b[%d]=%c\n",i,a[i],i,b[i]); 
        getchar(); 
        if(a[i] == b[i])    tie++; 
        if((a[i] == 'C' && b[i] == 'J') || (a[i] == 'J' && b[i] == 'B') || (a[i] == 'B' && b[i]== 'C') ) 
        {
            win++;
            if(a[i] == 'B') ca[1]++;
            if(a[i] == 'C') ca[2]++;
            if(a[i] == 'J') ca[3]++;
           // printf("win++ a[i]=%c b[i]=%c\n",a[i],b[i]);
        }
           
         if((b[i] == 'C' && a[i] == 'J') || (b[i] == 'J' && a[i] == 'B') || (b[i] == 'B' && a[i]== 'C') )
         {
            lose++;
            if(b[i] == 'B') cb[1]++;
            if(b[i] == 'C') cb[2]++;
            if(b[i] == 'J') cb[3]++;
         }
    }
    printf("%d %d %d\n%d %d %d\n",win,tie,lose,lose,tie,win);
   // printf("%d %d %d",ca[1],ca[2],ca[3]);
   // printf("\n%d %d %d",cb[1],cb[2],cb[3]);
    int cca=0;
    if(ca[1]>ca[2])
        cca=1;
    else
       if(ca[1]<ca[2]) 
        cca=2;
    if(ca[1]<ca[3] && ca[2]<ca[3])
        cca=3;
    //printf("cca=%d",cca);
    int ccb=0;
    if(cb[1]>cb[2])
        ccb=1;
    else
        if(cb[1]<cb[2])
        ccb=2;
    if(cb[1]<cb[3] && cb[2]<cb[3])
        ccb=3;
    //printf("ccb=%d",ccb);
    switch(cca)
    {
        case 0: printf("B "); break;
        case 1: printf("B "); break;
        case 2: printf("C "); break;
        case 3: printf("J "); break;
    }
    switch(ccb)
    {
        case 0: printf("B\n"); break;
        case 1: printf("B\n"); break;
        case 2: printf("C\n"); break;
        case 3: printf("J\n"); break;

    }
    return 0;
}
