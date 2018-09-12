/*
 * =========================================================================
 *
 *       Filename:  ny0123-2.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=123
 *
 *        Version:  (树状数组)
 *        Created:  2018/07/24 01时30分48秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int N = 1000010;
int bit[N+1];
int t,n,l,r,x;
char s[10];

int lowbit(int i)
{
    return i&-i;
}

int sum1(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= lowbit(i);
    }
    return s;
}

void add1(int i,int x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

void add(int i,int x)
{
	while(i <= n)
	{
		bit[i] += x;
		i += lowbit(i);
	}
}
 
int sum(int M)
{
	int ans = 0;
	while(M > 0)
	{
		ans += bit[M];
		M -= lowbit(M);
	}
	return ans;
}





int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&t,&n);
    for(int i = 1;i <= t;i++)
    {
        scanf("%s",s);
        if(s[0] == 'A')
        {
            scanf("%d%d%d",&l,&r,&x);
            add(l,x);
            add(r+1,-x);
            // cout << "4" << endl;
        }
        else 
        {
            scanf("%d",&x);
            printf("%d\n",sum(x));
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

