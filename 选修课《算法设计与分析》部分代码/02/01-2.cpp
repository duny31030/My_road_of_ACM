// 众数问题   （未考虑多个众数的问题）
#include <bits/stdc++.h>

using namespace std;
#define MAX  10010

int a[MAX];   // 存储多重集
int M = 0;  // 记录重数
int X; 
int length = 0;
void scan(int n)
{
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
}


void find(int l,int r)
{
	int ll,rr;
	int mid = (l+r)/2;
	ll = mid,rr = mid;
	int j = mid-1;
	while(a[j] == a[mid] && j >= l)
	{
		ll--;
		j--;
	}

	j = mid+1;
	while(a[j] == a[mid] && j < r)
	{
		rr++;
		j++;
	}

	// for(int j = mid-1;j >= l;j--)
	// {
	// 	if(a[j] != tmp)
	// 	{
	// 		ll = j+1;
	// 		break;
	// 	}
	// }
	

	// for(int j = mid+1;j < r;j++)
	// {
	// 	if(a[j] != tmp)
	// 	{
	// 		rr = j-1;
	// 		break;
	// 	}
	// }
	length = rr-ll+1;
	if(length > M)
	{
		M = length;
		X = a[mid];
	}
	// printf("length = %d\n",length);
	if(length < ll)
	{
		find(0,ll);
	}

	if(length < r-rr)
	{
		find(rr,r);
	}
}


int main()
{
	int n;   // 多重集大小 
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof a);   // 涉及多组输入，每次均初始化
		scan(n);   // 输入
		find(0,n);
		printf("%d %d\n",X,M);

	}
	return 0;
}