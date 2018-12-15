/*
 * =========================================================================
 *
 *       Filename:  V.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3068
 *
 *        Version:  1.0
 *        Created:  2018/08/28 12时30分11秒
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
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 110100;
char s[N],s_new[N*2];
int p[N*2];

int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    
    for(int i = 0;i < len;i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    
    s_new[j] = '\0';
    
    return j;   // 返回 s_new 的长度
}

int Manacher()
{
    int len = Init();   // 取得新字符串长度并完成向 s_new 的转换
	int max_len = -1;   // 最长回文长度

	int id;
	int mx = 0;

	for(int i = 1;i < len;i++)
	{
    	if(i < mx)
        	p[i] = min(p[2*id-i],mx-i);
    	else 
        	p[i] = 1;
    
    	while(s_new[i-p[i]] == s_new[i+p[i]])   // 不需要边界判断,因为有"$"、"\0"
    		p[i]++;
    
    	// 每走一步都要用i和mx比较
    	if(mx < i+p[i])
    	{
        	id = i;
        	mx = i+p[i];
    	}
    	max_len = max(max_len,p[i]-1);
	}
    return max_len;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(~scanf("%s",s))
    {
        getchar();
        printf("%d\n",Manacher());
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

