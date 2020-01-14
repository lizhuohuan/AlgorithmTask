/* 任务二：用递归调用实现快速排序和合并排序算法，语言不限。并随机生成测试算例，统计比较两种算法占用的间。
(二)合并排序
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 10

void MergeSort(int l[],int length);
void MSort(int l[],int tmp[],int left,int right);
void Merge(int l[],int tmp[],int left,int mid,int right);

void MergeSort(int l[],int lenght)
{
    int tmp[lenght];

    MSort(l,tmp,1,lenght);
}
/*分：MSort将原来的序列不断细分，直到为1，再由Merge归并*/
void MSort(int l[],int tmp[],int left,int right)
{
    int mid;

    if(left!=right)
    {
        mid=(left+right)/2;     //将待排序序列分成两部分
        MSort(l,tmp,left,mid);      //将左边排序
        MSort(l,tmp,mid+1,right);       //将右边排序
        Merge(l,tmp,left,mid,right);        //将已排序的两部分合并
    }
}
/*数组tmp只是作为临时存储，归并后，再将有序的数组拷贝到原来的l中*/
void Merge(int l[],int tmp[],int left,int mid,int right)
{
    int i,j,t;

    for(i=left,j=mid+1,t=left;i<=mid&&j<=right;t++)
    {
        if(l[i]<=l[j])
        {
            tmp[t]=l[i];
            i++;
        }
        else
        {
            tmp[t]=l[j];
            j++;
        }
    }
    /*归并的两个序列不一样长时，将剩余的元素加入tmp*/
    if(i<=mid)
    {
        for(;i<=mid;i++)
        {
            tmp[t]=l[i];
            t++;
        }
    }
    if(j<=right)
    {
        for(;j<=right;j++)
        {
            tmp[t]=l[j];
            t++;
        }
    }
    /*将归并后的有序序列拷贝到原数组*/
    for(t=left;t<=right;t++)
    {
        l[t]=tmp[t];
    }
}

int main()
{
    int i,x,a[NUM+1];
	printf("请输入%d个无序正整数：",NUM);
    for(i=1;i<=NUM;i++)
    {	scanf("%d",&x);
        a[i]=x;
    }
    MergeSort(a,NUM);
    printf("\n排序后:");
    for(i=1;i<=NUM;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

