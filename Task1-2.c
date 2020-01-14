/* 任务一：分别用循环和递归调用方式实现二分查找，语言不限。
2）递归调用
*/

#include<stdio.h>
#define N 8//数据长度，以10为例
 
int k[N];//数据数组，代码未加入排序算法，仅支持数组升序排序
int x,y;//待查找数据
void select(int a,int b)//a：下界		b：上界
{
	if(a<=b)//保证下界<=上界
	{
		if(k[(b-a)/2+a]<x)
		{
			select((b-a)/2+1,b);
			return;
		}//待查数据小于数组中心值，继续调用查找后半部分
		else if(k[(b-a)/2+a]>x)
		{
			select(a,(b-a)/2+a-1);
			return;
		}//待查数据小于数组中心值，继续调用查找后半部分
		else if(k[(b-a)/2+a]==x)
		{	y=(b-a)/2+a; 
			printf("已找到，位置为%d\n",(y+1));
			return;
		}//找到待查数据，输出此时的索引
		else 
		{
			printf("未找到\n");//待查数据未找到
			return;
		}
	}
	printf("未找到\n");//此处可能为多余部分，待证
	return;
}
 
main()
{
	int i;
	printf("请输入数据：\n");//获取数据
	for(i=0;i<N;i++)//循环获取
		scanf("%d",&k[i]);
	printf("数据输入完毕！\n");//数据接收完毕提示
	for(i=0;i<N;i++)
		printf("k[%d]=%d\n",i,k[i]);//显示获取的数据列表
	printf("输入要查询的数据：");
	scanf("%d",&x);//获取待查数据
	printf("查询的数据：%d\n",x);
	select(0,N);//调用函数，开始查询
}

