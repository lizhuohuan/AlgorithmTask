/*任务五：分别采用循坏和递归调用方式实现最长公共子序列的动态规划算法。
2）递归法：
*/
 
#include<stdio.h>
#include<string.h>
char a[30],b[30];
int lena,lenb;
int LCS(int ,int );       //两个参数分别表示数组a的下标和数组b的下标

int main()
{
    strcpy(a,"ABCBDAB");
    strcpy(b,"BDCABA");
    lena=strlen(a);
    lenb=strlen(b);
    printf("最长公共子序列的长度为：%d\n",LCS(0,0));
    return 0;
}

int LCS(int i,int j)
{
    if(i>=lena || j>=lenb)
        return 0;
    if(a[i]==b[j])
        return 1+LCS(i+1,j+1);
    else
        return LCS(i+1,j)>LCS(i,j+1)? LCS(i+1,j):LCS(i,j+1);
}

