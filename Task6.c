/* 任务六：背包问题的贪心算法。*/

#include<stdio.h>
#include<algorithm>
using namespace std;
/*定义结构体物品*/
struct node
{	
	int v,w;//v为价值w为物品重量
}a[101];

int cmp(node A,node B)
{
    return A.v>B.v;
}

int main()
{
    int i,j,sum,s,m,n;
    printf("输入一个正整数n（1<=n<=5）,表示有n组测试数据: "); 
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        printf("请输入物品个数s，和背包容量m: ");
        scanf("%d%d",&s,&m);//s为物品个数，m，为背包容量
        printf("请输入%d个物品的价值v和重量w:",s);
        for(i=0; i<s; i++)
            scanf("%d%d",&a[i].v,&a[i].w);
        sort(a,a+s,cmp);
        /*贪心算法核心*/
        for(i=0; i<s; i++)
        {
            if(m<a[i].w)
            {
                sum=sum+a[i].v*m;//背包可拆
                m=0;
                break;
            }
            else
            {
                sum=sum+a[i].v*a[i].w;
                m=m-a[i].w;
            }
        }
        printf("背包里的物品的价值总和最大值为：%d\n",sum);
    }
    return 0;
}

