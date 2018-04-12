#include <bits/stdc++.h>

using namespace std;



int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int sum = 0;
		int data[n+5][4];	// data[i][0]用来记录连锁值
		data[0][0] = 0;

		for(int i = 1;i <= n;i++)   // 输入同时判断连锁值
		{
			for(int j = 1;j <= 2;j++)   // 输入
			{
				scanf("%d",&data[i][j]);
			}
			if(data[i][2] <= 2)   //判断是否要输入x，即伤害值
				scanf("%d",&data[i][3]);


			// 输入的同时遍历一遍，依次记录连锁值
			// 例如
			// 下标 		1 2 3 4 5 6 7 8
			// 发动速度	1 2 2 3 2 1 3 4
			// 连锁值		1 2 3 4 1 1 2 3
			if(data[i][1] >= data[i-1][1]) 
				data[i][0] = data[i-1][0] +1;
			else
				data[i][0] = 1;
		}

		//按照生效顺序从后往前遍历
		for(int i = n;i > 0;i--)
		{
			//如果是第3、4种牌 且此连锁中这张牌前没有其他牌 则跳过
			if(data[i][2] > 2 && data[i][0] == 1)
			{
				// 跳过
			}
			else
				if(data[i][2] > 2 && data[i][0] >1)   // 如果是第3、4种牌 且同连锁中此牌前边还有其他牌 则进行判断
				{
					if(data[i][2] == 3)   // 如果为第3种牌，则直接跳过次连锁
					{
						i = i-data[i][0]+1;
					}
					else   // 第4种牌 则使前一张无效
					{
						i--;
					}
				}
				else
				{
					if(data[i][2] == 1)
					{
						sum += data[i][3];
					}
					else
					{
						sum += data[i][0]*data[i][3];
					}
				}
		}
		printf("%d\n",sum);

	}


	return 0;
}
