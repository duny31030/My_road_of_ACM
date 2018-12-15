/*
 * =========================================================================
 *
 *       Filename:  M.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2328
 *
 *        Version:  1.0
 *        Created:  2018/08/27 12时44分09秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 210;
char s[4010][N];
char T[N];
int slen[4010];
int Next[N],n;
void getNext(char T[],int tlen)
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < tlen)
    {
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
    }
}

int KMP_Index(char S[],char T[],int slen,int tlen)
{
    int i = 0,j = 0;
    getNext(T,tlen);

    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++;    j++;
        }
        else 
            j = Next[j];
    }
    if(j == tlen)
        return i-tlen;
    else 
        return -1;
}

bool check(char pr[],char T[],int len)
{
    int now = 0;
    while(pr[now] == T[now])
    {
        now++;
    }
    if(now < len)
    {
        if(pr[now] < T[now])
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
    else 
    {
        return false;
    }
}



int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d",&n)!=EOF)
    {
        int nlen = 0;
        char pr[N];
        clr(pr,0);
        if(n == 0)
            break;
        rep(i,1,n)
        {
            scanf("%s",s[i]);
            slen[i] = strlen(s[i]);
        }
        rep(i,1,slen[1])
        {
            for(int j = 0;j+i <= slen[1];j++)
            {
                clr(T,0);
                strncpy(T,s[1]+j,i);
                // printf("i = %d j = %d T = %s\n",i,j,T);
                int flag = 1;
                for(int k = 2;k <= n;k++)
                {
                    // printf("%d %s\n",KMP_Index(s[k],T,slen[k],i),T);
                    if(KMP_Index(s[k],T,slen[k],i) == -1)
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1)
                {
                    // printf("i = %d T = %s\n",i,T);
                    if(i >= nlen)
                    {
                        if(i > nlen)
                        {
                            nlen = i;
                            clr(pr,0);
                            strcpy(pr,T);
                        }
                        else 
                        {
                            if(check(pr,T,i))
                            {
                                clr(pr,0);
                                strcpy(pr,T);
                            }
                        }
                    }
                }
            }
        }
        if(nlen == 0)
            printf("IDENTITY LOST\n");
        else 
            printf("%s\n",pr);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

