#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//记录抢的属性
struct qi
{
    int p = 0;   //威力
    int k = 0;   //可装备配件数量
    int z[1010] = {0};   //可装备种类
}qi[1010];

//记录配件的属性
struct qii
{
    int q = 0;   //配件种类
    double b = 0;   //威力加成
}qii[1010];


int main()
{
    
    int n=0,m=0;   //n:枪支数量 m:配件数量
    double ma[1010]={0.0};
   
    
    
    while((scanf("%d %d",&n,&m))!=EOF)
    {
         double maxn = 0.0;
        for(int i=0;i<1010;i++)
        {
            ma[i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&qi[i].p,&qi[i].k);
            for(int j=1;j<=qi[i].k;j++)
            {
                scanf("%d",&qi[i].z[j]);
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d %lf",&qii[i].q,&qii[i].b);
        }
    
        for(int l=1;l<=m;l++)
        {
            //printf("\nqii[%d].b=%.4f\n",l,qii[l].b);
            if(qii[l].b > ma[qii[l].q])
                ma[qii[l].q]=qii[l].b;
        }
    
        //for(int i=1;i<=m;i++)
        //{
        //   printf("ma[%d]=%.4f\n",i,ma[i]);
        //}
    
        for(int i=1;i<=n;i++)
        {
            double m=1.0;
            for(int j=1;j<=qi[i].k;j++)
            {
                m += ma[qi[i].z[j]];
            }
            m *= qi[i].p;
            // printf("%d %.4f\n",i,m);
            if(maxn < m)
            {
                maxn = m;
            }
        
        }
        printf("%.4f\n",maxn);
    }   //while
    return 0;
}



