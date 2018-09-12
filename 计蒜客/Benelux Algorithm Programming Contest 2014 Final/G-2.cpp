/*
 * =========================================================================
 *
 *       Filename:  G-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/10 20时30分11秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <string.h>
int e[100000];
double f[100000];
int main()
{
    int d;
    scanf("%d",&d);
    double max1(int x);
    while(d--)
    {
        int n;

        while(scanf("%d",&n) != EOF)
        {
            for(int i = 0; i < 3*n ;i = i+3)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                e[i] = a;
                e[i+1] = b;
                e[i+2] = c;

            }

            for(int i = 0; i < 3*n;i = i + 3)
            {
                double temp = max1(i);
                f[i/3] = temp;
            }

            for(int i = 1;i < n;i++)
            {
                for(int j = i-1;j>=0&&f[j]>f[j+1];j--)
                {
                    double temp = f[j];
                    f[j] = f[j+1];
                    f[j+1] = temp;
                }
            }
            double max = f[n-1];
            
            int s;
            for(int i = 0;i < 3*n;i = i + 3)
            {
                if(max == max1(i))
                {
                    s = i;
                }
            }
            printf("%d\n",s/3+1);
            break;


        }

    }

}
double max1(int x)
        {
            double k = e[x+1]/(2*e[x]);
            double T = k*k*(-e[x]) + k*e[x+1]+e[x+2];


            return T;
        }
