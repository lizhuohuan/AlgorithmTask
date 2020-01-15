/* 任务八：用回溯法或分支限界法，实现从1~9中的自然数组成如()/()()+()/()()=()/()()等式，并且数字不能重复。 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d,e,f,g,h,i;
    for(a=1;a<=9;a++)
    {
        for(b=1;b<=9;b++)
        {
            for(c=1;c<=9;c++)
            {
                for(d=1;d<=9;d++)
                {
                    for(e=1;e<=9;e++)
                    {
                        for(f=1;f<=9;f++)
                        {
                        	for(g=1;g<=9;g++)
                        	{
                        		for(h=1;h<=9;h++)
                        		{
                        			for(i=1;i<=9;i++)
									{
										if( a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i
	                                     && b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i
	                                     && c!=d && c!=e && c!=f && c!=g && c!=h && c!=i
	                                     && d!=e && d!=f && d!=g && d!=h && d!=i
	                                     && e!=f && e!=g && e!=h && e!=i
										 && f!=g && f!=h && f!=i
										 && g!=h && g!=i
										 && h!=i)
			                            {
			                                if(a/(b*10+c)+d/(e*10+f)==g/(h*10+i))
			                                {
												
			                                   printf("%d%d%d%d%d%d%d%d%d\t",a,b,c,d,e,f,g,h,i);
			
			                                }
			                            }		
									}	
								}
							}                     
                        }
                    }
                }
            }
        }
    }
	printf("\n");

    system("pause");
    return 0;
}

