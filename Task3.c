/* 任务三：设计算法从给定的n个数中找出最小的k个数。采用递归调用实现算法。
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int KeyType;
typedef struct
{	KeyType Key;
}LineList;

//快速排序 
void QuickSort(LineList r[],int first,int end)
{
	int i,j;
	LineList temp;
	i=first; j=end; temp=r[i];
	while(i<j)
	{
		while(i<j && temp.Key<= r[j].Key) j--;
			r[i]=r[j];
		while(i<j && r[i].Key<=temp.Key) i++;
			r[j]=r[i];
	}
	r[i]=temp;
	if (first<i-1) 	QuickSort(r,first,i-1);          //对左侧分区域进行快速排序 
	if (i+1<end)    QuickSort(r,i+1,end);            //对右侧分区域进行快速排序 
}

//排序后的输出 
 void OutList(LineList r[],int n)
 {
 	int i,k;
	printf("请输入要最小数的个数（0<k<n）：");
	scanf("%d",&k);
	printf("\n最小的%d个数为：",k);	
 	for(i=1;i<=k;i++)
 		printf("%2d",r[i]);
 }
 
 main()
{	
 	LineList r[MAXSIZE];
 	int n,i,l=1;
 	printf("请输入待排序表的长度：");
 	scanf("%d",&n);
 	printf("\n请输入%d个整数：",n);
 	for(i=1;i<=n;i++)
 		scanf("%d",&r[i]);
	printf("\n进行快速排序后，");		
	QuickSort(r,l,n);
 	OutList(r,n);
}

