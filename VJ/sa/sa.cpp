/*
 * =========================================================================
 *
 *       Filename:  sa.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/20 21时11分35秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 100050;
char s[N];
int y[N],x[N],c[N],sa[N],rk[N],height[N],wt[30];
int n,m;

void get_SA()
{
    for(int i = 1;i <= n;++i)   ++c[x[i]=s[i]];
    // c数组是桶
    // x[i]是第i个元素的第一关键字
    for(int i = 2;i <= m;++i)   c[i] += c[i-1];
    // 做c的前缀和,我们就可以得出每个关键字最多是在第几名
    for(int i = n;i >= 1;--i)   sa[c[x[i]]--] = i;
    for(int k = 1;k <= n;k <<= 1)
    {
        int num = 0;
        for(int i = n-k+1;i <= n;++i)   y[++num] = i;
        // y[i]表示第二关键字排名为i的数,第一关键字的位置
        // 第n-k+1到第n位是没有第二关键字的 所以排名在最前面
        for(int i = 1;i <= n;++i)   if(sa[i] > k)   y[++num] = sa[i]-k;
        // 排名为i的数 在数组中是否在第k位以后
        // 如果满足(sa[i]>k) 那么它可以作为别人的第二关键字,就把它的第一关
        // 键字的位置添加进y就行了
        // 所以i枚举的是第二关键字的排名，第二关键字靠前的先入队
        for(int i = 1;i <= m;++i)   c[i] = 0;
        // 初始化c桶
        for(int i = 1;i <= n;++i)   ++c[x[i]];
        // 因为上一次循环已经算出了这次的第一关键字,所以直接加就行了
        for(int i = 2;i <= m;++i)   c[i] += c[i-1];   // 第一关键字排名为1~i的个数
        for(int i = n;i >= 1;--i)   sa[c[x[y[i]]]--] = y[i],y[i] = 0;
        // 因为y的顺序是按照第二关键字的顺序来排的
        // 第二关键字靠后的,在同一个第一关键字桶中排名靠后
        // 基数排序
        swap(x,y);
        // 生成新的x时要用到旧的,把旧的复制下来
        x[sa[1]] = 1;   num = 1;
        for(int i = 2;i <= n;++i)   
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
        // 因为sa[i]已经排好序了,所以可以按排名枚举,生成下一次的第一关键字
        if(num == n)    break;
        m = num;
        // 这里有了新编号就不用122了
    }
}

void get_height()
{
    int k = 0;
    for(int i = 1;i <= n;++i)   rk[sa[i]] = i;
    for(int i = 1;i <= n;++i)
    {
        if(rk[i] == 1)  continue;   // 第一名height为0
        if(k)   --k;   // h[i] >= h[i-1]+1;
        int j = sa[rk[i]-1];
        while(j+k <= n && i+k <= n && s[i+k] == s[j+k]) ++k;
        height[rk[i]] = k;  // h[i] = height[rk[i]];
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
    int tmp;
    cin >> tmp;
    scanf("%s",s+1);
    n = strlen(s+1);
    m = 122;
    // m表示字符个数,ascii('z') = 122
    get_SA();
    get_height();
    for(int i = 1;i <= n;i++)
        printf("%d ",sa[i]);
    printf("\n");
    for(int i = 1;i <= n;i++)
        printf("%d ",rk[i]);
    printf("\n");
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

