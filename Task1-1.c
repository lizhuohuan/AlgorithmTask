/* 任务一：分别用循环和递归调用方式实现二分查找，语言不限。
1）循环法：
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int KeyType;
typedef struct
{
	KeyType key;
 } SearchL;

 //二分查找 
 int BinSearch(SearchL r[],int n,KeyType k)
 {
 	int low,high,mid;
 	low=1; high=n;
 	while(low<=high)
 	{
 		mid=(low+high)/2;
 		if(k==r[mid].key)
 			return(mid);
 		else if(k<r[mid].key)
 			high=mid-1;
 		else
 			low=mid+1;
	 }
	 return (0);
 }
 
 main()
 {
 	SearchL r[MAXSIZE];
	int i,n,x,address;
	printf("\n请输入表的元素个数(0-%d)：",MAXSIZE-1);
	scanf("%d",&n);
	printf("请按照从小到大的顺序输入%d个表中的关键字（整数）：",n);
	for(i=1;i<=n;i++)
		scanf("%d",&r[i].key);
	printf("请输入要查找的关键字：");
	scanf("%d",&x); 
	if((address=BinSearch(r,n,x))!=0)
		printf("该元素在表中的位置为：%d",address);
	else
		printf("该元素不在有序表中！");

 }

