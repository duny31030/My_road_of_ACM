#include <cstdio>

using namespace std;

int f[1000010],t[1000010];
int ans=0;

void Merge(int l,int m,int r)   //左右两个表合并成一个表
{
	int i=l,j=m+1,cnt=0;
	while(i<=m && j<=r)
	{
		if(f[i] <= f[j])
			t[cnt++] = f[i++];
		else
		{
			ans += m-i+1;
			t[cnt++] = f[j++];   //求解逆序数个数
		}
	}

	while(i <= m)   //若左表不空
		t[cnt++] = f[i++];
	while(j <= r)   //若右表不空
		t[cnt++] = f[j++];
	for(int k=0;k<cnt;)   //修改原数组
		f[l++] = t[k++];
}

void Merge_sort(int l,int r)   //归并排序
{
	if(l == r)
		return ;
	else
	{
		int m = (l+r) >> 1;
		Merge_sort(l,m);
		Merge_sort(m+1,r);
		Merge(l,m,r);
	}
}



int main()
{
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
	ans = 0;
	
	Merge_sort(0,n-1);

	printf("%d\n",ans);
	return 0;
}