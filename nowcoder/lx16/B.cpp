#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 别人的思路 贴过来
/*
*思路：考虑三个序列：
*1.输入的序列a
*2.通过调整a最少次数得到正确的序列b
*3.任意一个正确的辅助序列c
*/

int arr[100005];   // 输入的序列a
int f[100005];   // 辅助序列c
// 开一个下标可以为负数的数组
int data[200010] = {0};   // 分类并计数 
int *cnt = data+100005;   // 很精妙 用指针实现下标可以为负数的数组
int main()
{
	int n,ans = 0;
	cin >> n;
	// 输入
	for(int i = 0;i < n;++i)	scanf("%d",&arr[i]);
	// 生成任意一个正确序列，保存在f中
	// 这里设置为{1，2，3，4，~~~，4，3，2，1};
	f[0] = f[n-1] = 1;
	for(int i = 1;i <= n-1-i;++i)	f[i] = f[n-i-1] = 1+i;
	// 根据差值来分类并计数
	for(int i = 0;i < n;++i)	cnt[f[i]-arr[i]]++;
	ans = n;
	for(int i = -100000;i <= 100000;++i)
	{
		if(ans > n-cnt[i])
			ans = n-cnt[i];
		// ans = min(ans,n-cnt[i]);
	}
	// 输出结果
	printf("%d\n",ans);
	return 0;
}
